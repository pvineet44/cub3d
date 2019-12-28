/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:24:34 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/28 18:55:57 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include <stdlib.h>
//gcc -lmlx -framework OpenGL -framework AppKit scene.c

typedef struct 	wall_mlx
{
	int xr_t;
	int yr_t;
	int xl_t;
	int yl_t;
	int xr_b;
	int yr_b;
	int xl_b;
	int yl_b;
	int h;
	int w;
}				w_mlx;

typedef struct 	s_mlx
{
	void *mlx;
	void *win;
	int  bpp;
	int  size_line;
	int endian;
	int x;
	int y;
	w_mlx *w_mlx;
}				t_mlx;

int 	draw_s_wall(t_mlx *ph)
{
	// 1. draw wall
	// 2. save co-ordinates in w_mlx
	void *mlx = ph->mlx;
	void *win = ph->win;
	void *img;

	int bpp = 32;
	int size_line =  1600;
	int endian = 1;

	w_mlx *wall = ph->w_mlx;
	img = mlx_new_image(mlx, wall->h, wall->w);
	char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data;
	int c = 0;
	int pix = wall->h * wall->w * 4;
	while (c < pix)
	{
		*tmp++ = 102;
		*tmp++ = 255;
		*tmp++ = 255;
		c += 4;
	}
	wall->xr_t = wall->xl_t + wall->w;
	wall->yr_t = wall->yl_t;

	wall->xr_b = wall->xr_t;
	wall->yr_b = wall->yr_t + wall->h;

	wall->xl_b = wall->xl_t;
	wall->yl_b = wall->yl_t + wall->h;
	mlx_put_image_to_window(mlx, win, img, wall->xl_t, wall->yl_t);
	return (0);
}

int 	draw_top_line(t_mlx *ph)
{
	int start_x = 0;
	int start_y = 0;
	w_mlx *wall = ph->w_mlx;

	int end_x;
	int end_y;
	end_x = wall->xl_t;
	end_y = wall->yl_t;
	printf("start(x,y): %d,%d\n",start_x, start_y);
	printf("end(x,y): %d,%d\n",end_x, end_y);
	return (0);
}

int  	draw_l_wall(t_mlx *ph)
{
	draw_top_line(ph);
	//draw_bottom_line(ph);
	return (0);

}
int 	draw_scene(t_mlx *ph)
{
	draw_s_wall(ph);
	draw_l_wall(ph);
	// draw_r_wall();
	return (0);
}

int		key_hook(int keycode, t_mlx *ph)
{
	if (keycode == 6)
	{
		draw_scene(ph);
		return (0);
	}
	if (keycode == 8)
	{
		//zoom_scene(ph)
		return (0);
	}
	return(0);
}

w_mlx	init(w_mlx wall_mlx)
{
	wall_mlx.xr_t = 0;
	wall_mlx.yr_t = 0;
	wall_mlx.xl_t = 200;
	wall_mlx.yl_t = 100;
	wall_mlx.xr_b = 0;
	wall_mlx.yr_b = 0;
	wall_mlx.xl_b = 0;
	wall_mlx.yl_b = 0;
	wall_mlx.h = 400;
	wall_mlx.w = 400;
	return (wall_mlx);
}
int main(int argc, const char *argv[])
{
	void *mlx;
	void *win;
	t_mlx ph;
	w_mlx wall_mlx;
	wall_mlx = init(wall_mlx);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "scene");
	ph.mlx = mlx;
	ph.win = win;
	ph.w_mlx = &wall_mlx;
	mlx_key_hook(win, key_hook, &ph);
	mlx_loop(mlx);
	return 0;
}
