/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:36:13 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/27 16:41:27 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
//gcc -lmlx -framework OpenGL -framework AppKit hook.c

typedef struct 	w_mlx
{
	int xr_t;
	int yr_t;
	int xl_t;
	int yl_t;
	int xr_b;
	int yr_b;
	int xl_b;
	int yl_b;
}				wall_mlx;


typedef struct 	s_mlx
{
	void *mlx;
	void *win;
	int  bpp;
	int  size_line;
	int endian;
	int x;
	int y;
	wall_mlx w_mlx;
}				t_mlx;





int key_hook(int keycode, t_mlx *ph)
{

	void *mlx = ph->mlx;
	void *win = ph->win;

	if (keycode == 8)
	{
		mlx_clear_window(mlx, win);
		return(0);
	}
	if (keycode  == 6)
	{
		zoom_square(ph);
		return(0);
	}
	if (keycode == 53)
	{
		write(1, "Exiting program..\n", 18);
		mlx_clear_window(mlx, win);
		mlx_destroy_window(mlx, win);
		exit(0);
		return (0);
	}
	void *img;
	void *img2;

	int     bpp = 32;
	int     size_line  = 1600;
	int     endian = 1;

	static int i = 0;
	img = mlx_new_image(mlx, 200,200);
	char    *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data + i;
	int c = 0;
	while(c < 400)
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	i = i + 4;
	mlx_put_image_to_window(mlx, win, img, 50,50);
	return (0);
}

int draw_hline(int x, int y, t_mlx *ph)
{
	void *mlx = ph->mlx;
	void *win = ph->win;
	int bpp = 32;
	int size_line = 1600;
	int endian = 1;
	void *img;
	img = mlx_new_image(mlx, 200,1);
	char *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data;
	int c = 0;
	while(c < 400)
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (0);
}

int draw_scene(int keycode, t_mlx *ph)
{
	//draw square

	//draw left wall
	//draw right wall
}

int zoom_square(t_mlx *ph)
{
	static int i;
	void *mlx = ph->mlx;
	void *win = ph->win;
	int bpp = 32;
	int size_line = 1600;
	int endian = 1;
	void *img;
	int x;
	int y;
	x = ph->x;
	y = ph->y;
	i = i + 5;
	int h;
	int w;
	h = 200 + i;
	w = 200 + i;
	int pix = h * w * 4;
	img = mlx_new_image(mlx, h, w);
	mlx_clear_window(mlx, win);
	char *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data;
	int c = 0;
	while(c < pix)
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	mlx_put_image_to_window(mlx, win, img, x, y);	
}

int draw_square(int x, int y, t_mlx *ph)
{
	void *mlx = ph->mlx;
	void *win = ph->win;
	wall_mlx w_mlx = ph->w_mlx
	int bpp = 32;
	int size_line = 1600;
	int endian = 1;
	void *img;
	img = mlx_new_image(mlx, 400,400);
	char *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data;
	x = 200;
	y = 100;

	int c = 0;
	while(c < 640000)
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	mlx_put_image_to_window(mlx, win, img, x, y);

	w_mlx.xr_l = x 
	
}

int draw_vline(int x, int y, t_mlx *ph)
{
	void *mlx = ph->mlx;
	void *win = ph->win;
	int bpp = 32;
	int size_line = 1600;
	int endian = 1;
	void *img;
	img = mlx_new_image(mlx, 1,200);
	char *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data;
	int c = 0;
	while(c < 400)
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	mlx_put_image_to_window(mlx, win, img, x, y);
	mlx_put_image_to_window(mlx, win, img, x+10, y+10);
	return (0);
}

int mouse_hook(int button, int x, int y, t_mlx *ph)
{
	if (button == 1)
		draw_square(x, y ,ph);
	if (button == 2)
		draw_square(x, y ,ph);
	

	void *mlx = ph->mlx;
	void *win = ph->win;
	mlx_pixel_put(mlx, win, x, y, 0xFF00FF);
	return (0);
}
int loop_hook(t_mlx *ph)
{
	write(1, "No event\n", 9);
	return (0);
}
int main(int argc, const char *argv[])
{
	void *mlx;
	void *win;
	void *img;
	t_mlx pointer_holder;
	pointer_holder.bpp = 32;
	pointer_holder.size_line  = 1600;
	pointer_holder.endian = 1;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "42");
	pointer_holder.mlx = mlx;
	pointer_holder.win = win;
	mlx_key_hook(win, key_hook, &pointer_holder);
	//mlx_loop_hook(mlx, loop_hook, &pointer_holder);
	mlx_mouse_hook(win, mouse_hook, &pointer_holder);
	mlx_loop(mlx);
	return 0;
}
