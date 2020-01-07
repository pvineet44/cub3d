/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lrc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:57:03 by mashar            #+#    #+#             */
/*   Updated: 2020/01/06 16:18:05 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>



#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480


typedef struct s_move{
  double posX; 
  double posY;//x and y start position
  double dirX;
  double dirY;//initial direction vector
  double planeX;
  double planeY; //the 2d raycaster version of camera plane
  void *mlx;
  void *win;
}   move;

void  draw_column(int x, int drawStart, int drawEnd, char colour, void *mlx,\
void *win)
{
  int R = 0;
  int G = 0;
  int B = 0;
  int A = 1;

  if  (colour == 'r')
  {
    R = 255;
    G = 0;
    B = 0;
    A = 1;
  }
  if  (colour == 'b')
  {
    R = 3;
    G = 134;
    B = 251;
    A = 1;
  }
  if  (colour == 'g')
  {
    R = 0;
    G = 173;
    B = 16;
    A = 1;
  }
  if  (colour == 'y')
  {
    R = 251;
    G = 247;
    B = 3;
    A = 1;
  }
  if  (colour == 'w')
  {
    R = 255;
    G = 255;
    B = 255;
    A = 1;
  }
  int bpp;
  //printf("color : %x\n",colour);
  int endian;
  int size_line;
  int height = drawEnd - drawStart;
  char *img = mlx_new_image(mlx, 1, height);
  char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
  char *tmp = img_data;
  int pix = 4 * height;
  int c = 0;
  while (c < pix)
  {
    *tmp++ = B;
    *tmp++ = G;
    *tmp++ = R;
    *tmp++ = A;
    c += 4;
  }
  mlx_put_image_to_window(mlx, win, img, x, drawStart);
}

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



void paint(move *mv)
{

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame
  
  double height = 480;
  double width  = 640;

  for(int x = 0; x < 640; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (width) - 1; //x-coordinate in camera space
      double rayDirX = mv->dirX + mv->planeX * cameraX;
      double rayDirY = mv->dirY + mv->planeY * cameraX;
    
      // printf("\n\nrayDirY : %f\n", rayDirY);
      //while(1);

    //which box of the map we're in
      int mapX = (mv->posX);
      int mapY = (mv->posY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);

      // printf("\n\nDeltadistY : %f\n", deltaDistY);
     
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?


      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (mv->posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - mv->posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (mv->posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - mv->posY) * deltaDistY;
      }
      
           //perform DDA
      while (hit == 0)
      {
        printf("sideDistX: %f\tsideDistY:%f\n", sideDistX, sideDistY);
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        //write (1, "", 2); 

         if ( mapX < 24 && mapY < 24 && worldMap[mapX][mapY] > 0)
          hit  = 1;
      }
      if (side == 0)
         perpWallDist = (mapX - mv->posX + (1 - stepX) / 2) / rayDirX;
      else
          perpWallDist = (mapY - mv->posY + (1 - stepY) / 2) / rayDirY; 
    

      // printf("player->perpWallDist: %f\n", perpWallDist);
      //  printf("mapX: %d \t position.X: %f \t stepX: %d \t rayDirX: %f\n", mapX, mv->posX, stepX, rayDirX);
      //  printf("mapY: %d \t position.Y: %f \t stepY: %d \t rayDirY: %f\n", mapY, mv->posY, stepY, rayDirY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(3 * height / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + height / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + height / 2;
      if(drawEnd >= height)drawEnd = height - 1;

      char colour;
     switch(worldMap[mapX][mapY])
      {
        case 1: colour = 'b';
            break;
        case 2: colour = 'g';
            break;
        case 4: colour = 'r';
            break;
        case 3: colour = 'w';
            break;
        default : colour = 'y';
      }
  //printf("color is : %c", colour);
      //give x and y sides different brightness
      // if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
    draw_column(x, drawStart, drawEnd, colour, mv->mlx, mv->win);


    }
}


void rotate(int key, move *mov)
{
  double  oldDirX;
  double oldPlaneX;

  oldPlaneX = mov->planeX;
  oldDirX = mov->dirX;
  float rot_angle = 0.045;
  printf("\nKey: %d\n", key);
  if (key == 123)//left rotate
  {
    mov->dirX = (mov->dirX * cos(rot_angle)) - (mov->dirY * sin(rot_angle));
    mov->dirY = (oldDirX * sin (rot_angle)) + (mov->dirY * cos(rot_angle));
    mov->planeX = (mov->planeX * cos(rot_angle)) - (mov->planeY * sin(rot_angle));
    mov->planeY = (oldPlaneX * sin(rot_angle)) + (mov->planeY * cos(rot_angle)); 
  }
  if (key == 124)//right rotate
  {
    mov->dirX = (mov->dirX * cos(-rot_angle)) - (mov->dirY * sin(-rot_angle));
    mov->dirY = (oldDirX * sin (-rot_angle)) + (mov->dirY * cos(-rot_angle));
    mov->planeX = (mov->planeX * cos(-rot_angle)) - (mov->planeY * sin(-rot_angle));
    mov->planeY = (oldPlaneX * sin(-rot_angle)) + (mov->planeY * cos(-rot_angle)); 
  }

}

void walk(int key, move *mov)
{
  float moveSpeed = 0.5;
  printf("\nKey: %d\n", key);
  if (key == 13 || key == 126)
  {
    printf("matrix number: [%d][%d]\n", (int)(mov->posX + mov->dirX * moveSpeed),(int)(mov->posY));
    printf("matrix data [%d]", worldMap[(int)(mov->posX + mov->dirX * moveSpeed)][(int)(mov->posY)]);

      if (worldMap[(int)(mov->posX + mov->dirX * moveSpeed)][(int)(mov->posY)] == 0) 
      {
        printf("\nhere");
        mov->posX += mov->dirX * moveSpeed;
      }
      if(worldMap[(int)(mov->posX)][(int)(mov->posY + mov->dirY * moveSpeed)] == 0)
        {
          printf("\nhere");
          mov->posY += mov->dirY * moveSpeed;
        }

  }
  if (key == 1 || key == 125)
  {
    if(worldMap[(int)(mov->posX - mov->dirX * moveSpeed)][(int)(mov->posY)] == 0)
      mov->posX -= mov->dirX * moveSpeed;
    if(worldMap[(int)(mov->posX)][(int)(mov->posY - mov->dirY * moveSpeed)] == 0)
      mov->posY -= mov->dirY * moveSpeed;
  }
}

int key_hook(int key,move *move)
{
  mlx_clear_window(move->mlx,move->win);
  if (key == 53)
    exit(0);
  else if (key == 123 || key == 124)
      rotate(key, move);
  else if (key == 125 || key == 126 || key == 13 || key == 1)
        walk(key, move);
  paint(move);
  return 0;
}


int main(int ac/*argc*/, char **av/*argv*/)
{
  void *win;
  void *mlx;
  move mv;
  mv.posX = 22;
  mv.posY = 12;  //x and y start position
  mv.dirX = -1;
  mv.dirY = 0; //initial direction vector
  mv.planeX = 0;
  mv.planeY = 0.66; //the 2d raycaster version of camera plane


	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "LRC");
  mv.win = win;
  mv.mlx=mlx;  
	paint(&mv);
  mlx_key_hook(win, key_hook, &mv);
  printf("icicicic\n");

	mlx_loop(mlx);
}


