/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lrc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:57:03 by mashar            #+#    #+#             */
/*   Updated: 2020/01/05 19:12:01 by mashar           ###   ########.fr       */
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

void  draw_column(int x, int drawStart, int drawEnd, char colour, void *mlx,\
void *win)
{
  int R = 0;
  int G = 0;
  int B = 0;
  int A = 1;

  if  (colour == 'r')
  {
  write(1, "r", 1);
    R = 255;
    G = 45;
    B = 0;
    A = 1;
  }
  if  (colour == 'b')
  {
  write(1, "b", 1);
    R = 3;
    G = 134;
    B = 251;
    A = 1;
  }
  if  (colour == 'g')
  {
    write(1, "g", 1);
    R = 0;
    G = 173;
    B = 16;
    A = 1;
  }
  if  (colour == 'y')
  {
    write(1, "y", 1);
    R = 251;
    G = 247;
    B = 3;
    A = 1;
  }
  if  (colour == 'w')
  {
    write(1, "w", 1);
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
  printf("\nR: %d\n", R);
  printf("G: %d\n", G);
  printf("B: %d\n", B);
  printf("A: %d\n", A);
  while (c < pix)
  {
    *tmp++ = R;
    *tmp++ = G;
    *tmp++ = B;
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

int main(int ac/*argc*/, char **av/*argv*/)
{
	double posX = 15, posY = 15;  //x and y start position
	double dirX = 1, dirY = 1; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	void *win;
	void *mlx;
  double height = 480;
  double width  = 640;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "LRC");
  
	for(int x = 0; x < 640; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (width) - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;

	  //which box of the map we're in
      int mapX = (posX);
      int mapY = (posY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
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
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
           //perform DDA
      while (hit == 0)
      {
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
      	 perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      else
      	  perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY; 


      //Calculate height of line to draw on screen
      int lineHeight = (int)(2 *height / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + height / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + height / 2;
      if(drawEnd >= height)drawEnd = height - 1;

   	  char colour;
     switch(worldMap[mapX][mapY])
      {
        case 1: colour = 'r';
            break;
        case 2: colour = 'g';
            break;
        case 4: colour = 'b';
            break;
        case 3: colour = 'w';
            break;
        default : colour = 'y';
      }
	printf("color is : %c", colour);
      //give x and y sides different brightness
      // if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      draw_column(x, drawStart, drawEnd, colour, mlx, win);
    }
	mlx_loop(mlx);
}

