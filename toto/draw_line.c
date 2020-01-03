/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:37:17 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/02 18:52:43 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
typedef		struct		s_point
{
	int x;
	int y;
}						point;

typedef		struct		s_hold
{
	void *mlx;
	void *win;
	point a;
	point b;
}						hold;

point			init_point(point p)
{
	p.x = 0;
	p.y = 0;
	return (p);
}

hold			init_hold(hold h)
{
	h.mlx = 0;
	h.win = 0;
	h.a = init_point(h.a);
	h.b = init_point(h.b);
	return (h);
}

void		swap(int *a, int*b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

point		rotate_line(point a, point b, int clockwise)
{
	point p;
	p = init_point(p);
	double degree;
	double radian;
	degree = 5;
	if (clockwise)
		degree = 360 - degree;
	radian = degree * 0.01745;
	p.x = (int)(a.x + ((b.x - a.x)*cos(radian) - (b.y - a.y)*sin(radian)));
	p.y = (int)(a.y + ((b.x - a.x)*sin(radian) + (b.y - a.y)*cos(radian)));
	return (p);
}

void	line(int x0, int y0, int x1, int y1, hold h)
{
 	void *mlx = h.mlx;
	void *win = h.win;
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  	int err = (dx>dy ? dx : -dy)/2, e2;
 
  	for(;;){
   	 	mlx_pixel_put(mlx, win, x0, y0, 0xffffff);
    if (x0==x1 && y0==y1) break;
    	e2 = err;
    	if (e2 >-dx) { err -= dy; x0 += sx; }
    	if (e2 < dy) { err += dx; y0 += sy; }
  }
}

int		draw_line(hold h)
{
	int x1;
	int y1;
	int x2;
	int y2;
	point a;
	point b;
	a = h.a;
	b = h.b;

	x1 = a.x;
	y1 = a.y;
	x2 = b.x;
	y2 = b.y;
	// write(1, "jojojo", 6);
	line(a.x, a.y, b.x, b.y, h);
	return (0);
}

hold		step_forward(hold h)
{
	point a; 
	point b;

	a = h.a;
	b = h.b;
	a.y -= 5;
	b.y -= 5;
	line(a.x, a.y, b.x, b.y, h);
	h.a = a;
	h.b = b;
	return (h);
}
hold		step_backward(hold h)
{
	point a; 
	point b;

	a = h.a;
	b = h.b;
	a.y += 5;
	b.y += 5;
	line(a.x, a.y, b.x, b.y, h);
	h.a = a;
	h.b = b;
	return (h);
}


hold		strafe_right(hold h)
{
	point a; 
	point b;

	a = h.a;
	b = h.b;
	a.x += 5;
	b.x += 5;
	line(a.x, a.y, b.x, b.y, h);
	h.a = a;
	h.b = b;
	return (h);
}

hold		strafe_left(hold h)
{
	point a; 
	point b;

	a = h.a;
	b = h.b;
	a.x -= 5;
	b.x -= 5;
	line(a.x, a.y, b.x, b.y, h);
	h.a = a;
	h.b = b;
	return (h);
}


int		key_hook(int keycode, hold *h)
{
	
	// if (keycode  == 124)
	// {
	// 	mlx_clear_window(h->mlx, h->win);	
	// 	point p = rotate_line(h->a, h->b, 0);
	// 	h->b = p;
	// 	draw_line(*h);
	// }

	// if (keycode  == 123)
	// {
	// 	mlx_clear_window(h->mlx, h->win);	
	// 	point p = rotate_line(h->a, h->b, 1);
	// 	h->b = p;
	// 	draw_line(*h);
	// }

	if (keycode == 2)
	{
		mlx_clear_window(h->mlx, h->win);
		*h = strafe_right(*h);
	}

	if (keycode == 0)
	{
		mlx_clear_window(h->mlx, h->win);
		*h = strafe_left(*h);
	}

	if (keycode == 13)
	{
		mlx_clear_window(h->mlx, h->win);
		*h = step_forward(*h);
	}
	if (keycode == 1)
	{
		mlx_clear_window(h->mlx, h->win);
		*h = step_backward(*h);
	}

	return (0);
}

int main(int argc, const char *argv[])
{
	void *win;
	void *mlx;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Brez_line");
	hold h;
	h = init_hold(h);
	h.mlx = mlx;
	h.win = win;
	point a;
	a = init_point(a);
	a.x = 200;
	a.y = 300;
	mlx_pixel_put(mlx, win, a.x, a.y, 0xffffff);
	point b;
	b = init_point(b);
	b.x = 400;
	b.y = 300;
	mlx_pixel_put(mlx, win, b.x, b.y, 0xffffff);
	h.a = a;
	h.b = b;
	line(a.x, a.y, b.x, b.y, h);
	mlx_key_hook(win, key_hook, &h);
	mlx_loop(mlx);
	return (0);
}
