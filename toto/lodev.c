/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:47:49 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/05 17:56:43 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#define map_width		24
#define map_height		24
#define	screen_width	640
#define	screen_height	480

#define RED 0xff2d00
#define GREEN 0x00ad10
#define BLUE 0x0386fb
#define YELLOW 0xfbf703
#define WHITE 0xffffff
#include <math.h>
int world_map[map_width][map_height]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
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

void	draw_column(int x, int drawStart, int drawEnd, char colour, void *mlx,\
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
	printf("R: %d\n", R);
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

int main(int argc, const char *argv[])
{
	double posX = 8;
	double posY = 22;
	double dirX = -1;
	double	dirY = 0;
	double planeX = 0;
	double planeY = 0.66;

	double time = 0;
	double oldTime = 0;
	

	int done = 1;

	//start variables for the raycasting loop
	int x;
	x = 0;
	double cameraX;
	double cameraY;
	double rayDirX, rayDirY;
	int mapX, mapY;
	double sideDistX, sideDistY;
	double deltaDistX, deltaDistY;
	double perpWallDist;
	
	int stepX;
	int stepY;

	int hit = 0;
	int side;
	int lineHeight;

	int drawStart;
	int drawEnd;

	char colour;
	//end variables for the raycasting loop

	void *win;
	void *mlx;
	mlx = mlx_init();
	win = mlx_new_window(mlx, screen_width, screen_height, "lodev");
	while (x <  screen_width)
	{
			hit = 0;
	//calculate every ray position and directionn 
		cameraX = (2 * x) / (screen_width) - 1.0;
		rayDirX = dirX + (planeX * cameraX);
		rayDirY = dirY + (planeY * cameraY);
		mapX = (int)(posX);
		mapY = (int)(posY);

		deltaDistX = fabs(1/rayDirX);
		deltaDistY = fabs(1/rayDirY);
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX -  posX + 1.0) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY - posY + 1.0) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += deltaDistX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (world_map[mapX][mapY] > 0)
				hit = 1;
		}
			if (side == 0)
				perpWallDist = ((mapX - posX + (1 - stepX)/2) / rayDirX);
			else
				perpWallDist = ((mapY - posY + (1 - stepY)/2) / rayDirY);
			//calculate the height of line to draw on screen
			lineHeight = (int) (screen_height / perpWallDist);
			//calculate the lowest and highest pixel to fill in current stripe
			drawStart = -lineHeight / 2 + screen_height / 2;
			if (drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + screen_height / 2;
			if (drawEnd >= screen_height)
				drawEnd = screen_height - 1;
			switch(world_map[mapX][mapY])
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
			if (side == 1)
				colour = 'g';
			draw_column(x, drawStart, drawEnd, colour, mlx, win);
	x++;
	}
	mlx_loop(mlx);

	return (0);
}
