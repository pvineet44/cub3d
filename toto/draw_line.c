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
		degree = -degree;
	radian = degree * 0.01745;
	p.x = (int)(a.x + ((b.x - a.x)*cos(radian) - (b.y - a.y)*sin(radian)));
	p.y = (int)(a.y + ((b.x - a.x)*sin(radian) + (b.y - a.y)*cos(radian)));
	return (p);
}

void line(int x0, int y0, int x1, int y1, hold h)
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

int draw_line(hold h)
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
	line(x1, y1, x2, y2, h);
	return (0);
}

int		key_hook(int keycode, hold *h)
{
	int clockwise = 0;
	if (keycode  == 124)
	{
		mlx_clear_window(h->mlx, h->win);	
		point p = rotate_line(h->a, h->b, clockwise);
		h->b = p;
		draw_line(*h);
	}

	if (keycode  == 123)
	{
		clockwise = 1;
		mlx_clear_window(h->mlx, h->win);	
		point p = rotate_line(h->a, h->b, clockwise);
		h->b = p;
		draw_line(*h);
	}

	if (keycode == 126)
	{
		mlx_clear_window(h->mlx, h->win);
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
	a.y = 200;
	mlx_pixel_put(mlx, win, a.x, a.y, 0xffffff);
	point b;
	b = init_point(b);
	b.x = 250;
	b.y = 200;
	mlx_pixel_put(mlx, win, b.x, b.y, 0xffffff);
	//draw_line(h);
	h.a = a;
	h.b = b;
	mlx_key_hook(win, key_hook, &h);
	mlx_loop(mlx);
	return (0);
}
