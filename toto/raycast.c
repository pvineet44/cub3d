/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:57:29 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/30 19:17:39 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
//gcc -lmlx -framework OpenGL -framework AppKit raycast.c

typedef		struct		s_vector
{
	float x1;
	float y1;
	float x2;
	float y2;
}						vector;

vector			init_vector(vector v)
{
	v.x1 = 0;
	v.x2 = 0;
	v.y1 = 0;
	v.y2 = 0;
	return (v);
}

typedef		struct		s_mlx
{
	void *mlx;
	void *win;
}						t_mlx;

float			calculate_t(vector v1, vector v2)
{
	float x1;
	float x2;
	float x3;
	float x4;

	float y1;
	float y2;
	float y3;
	float y4;
	x1 = v1.x1;
	y1 = v1.y1;
	x2 = v1.x2;
	y2 = v1.y2;

	x3 = v2.x1;
	y3 = v2.y1;
	x4 = v2.x2;
	y4 = v2.y2;
	float den = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));
	if (den == 0)
		return (99);
	float num = ((x1 - x3) * (y3 - y4)) - ((y1 - y3) * (x3 - x4));
	float t = num/den;
	float u_num = ((x1 - x2) * (y1 - y3)) - ((y1 - y2) * (x1 - x3));
	float u_den = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));
	float u = 0;
	u = -u_num/u_den;
	printf("u: %f\n",u);

	if (u > 0)
		return (t);
	return (99);
}

vector		point_of_intersection(vector v1, vector v2, float t, void *mlx, void *win)
{
	float x1;
	float x2;
	float x3;
	float x4;


	float y1;
	float y2;
	float y3;
	float y4;
	x1 = v1.x1;
	y1 = v1.y1;
	x2 = v1.x2;
	y2 = v1.y2;

	x3 = v2.x1;
	y3 = v2.y1;
	x4 = v2.x2;
	y4 = v2.y2;
	vector v;
	v = init_vector(v);
	v.x1 = x1 + t*(x2 - x1);
	v.y1 = y1 + t*(y2 - y1);
	printf("t: %f\n",t);
	printf("y2: %f\n",y2);
	printf("y1: %f\n", y1);
	draw_pixel(v, mlx, win);
	return (v);
}


int		draw_stepped_line(void *mlx, void *win)
{
	mlx_clear_window(mlx, win);
	int x = 300;
	int y = 300;
	static	int stepsize;
	int i = 0;
	int length = 0;
	stepsize+=5;
	while(length < 200)
	{
		i = 0;
		while (i < stepsize && length < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xf0f0f0);
			i++;
			x++;
			length++;
		}
		y++;
	}
	return (0);
}
int		key_hook(int keycode, t_mlx *ph)
{
	if (keycode != 124)
		return (99);
	void *mlx = ph->mlx;
	void *win = ph->win;
	draw_stepped_line(mlx, win);
	return (0);
}


int draw_slant_line(void *mlx, void *win)
{
	int i = 150;
	int j = 150;
	int c = 0;
	while (c < 1)
	{
		while (i < 200)
		{
	//		mlx_pixel_put(mlx, win, i,j,0xff00ff);
			i++;
			j++;
		}
		c++;
	}
	return (0);
}

int draw_pixel(vector p, void *mlx, void *win)
{
	int x = p.x1;
	int y = p.y1;
	int bpp;
	int size_line;
	int endian;
	char *img = mlx_new_image(mlx, 10, 1);
	char *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data;
	int c = 0;
	while(c < 40)
	{
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (0);
}


int main(int argc, const char *argv[])
{
	void *win;
	void *mlx;
	int bpp;
	int size_line;
	int endian;
	t_mlx ph;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Cube3d");
	ph.mlx = mlx;
	ph.win = win;
	//draw_slant_line(mlx, win);
	//draw_wall
	vector v_wall;
	v_wall = init_vector(v_wall);

	char *img = mlx_new_image(mlx, 1,400);
	char *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);

	char *tmp = img_data;
	int c = 0;
	while(c < 1600)
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			c = c + 4;
	}
	mlx_put_image_to_window(mlx, win, img, 600, 60);
	v_wall.x1 = 600;
	v_wall.y1 = 60;
	v_wall.x2 = 600;
	v_wall.y2 = 460;
	//Draw ray 
	void *ray = mlx_new_image(mlx, 100, 100);
	vector v_ray;
	v_ray = init_vector(v_ray);

	char *ray_data =  mlx_get_data_addr(ray, &bpp, &size_line, &endian);
	char *tmp1 = ray_data;
	int d = 0;
	while(d < 400)
	{
			*tmp1++ = 102;
			*tmp1++ = 255;
			*tmp1++ = 255;
			*tmp1++ = 1;
			tmp1 = tmp1 + (100 * 4);
			d = d + 4;
	}
	mlx_put_image_to_window(mlx, win, ray, 300, 260);
	v_ray.x1 = 300;
	v_ray.y1 = 260;
	v_ray.x2 = 400;
	v_ray.y2 = 260;
	float t = calculate_t(v_wall, v_ray);
	vector p;
	if (t > 0)
	 p = point_of_intersection(v_wall, v_ray, t, mlx, win);
	else
		write(1, "aaaa", 4);
	//draw_pixel(p, mlx, win);
	mlx_key_hook(win, key_hook, &ph);
	mlx_loop(mlx);
	return 0;
}
