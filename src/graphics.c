/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:07:50 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:07:52 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rect(t_window *window, t_rect rect, unsigned char color[4])
{
	int i;
	int j;

	i = -1;
	while (++i < rect.width)
	{
		j = -1;
		while (++j < rect.height)
			draw_pixel(window, rect.x + i, rect.y + j, color);
	}
}

void	clear_data(t_window *window)
{
	t_rect			rect;
	unsigned char	color[4];

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	color[3] = 0;
	rect.x = 0;
	rect.y = 0;
	rect.width = window->width;
	rect.height = window->height;
	draw_rect(window, rect, color);
}

void	draw_pixel(t_window *window, unsigned int x, unsigned int y,
	unsigned char color[4])
{
	int index;
	int	i;

	if (x >= window->width || y >= window->height)
		return ;
	index = x * 4 + y * 4 * window->width;
	i = -1;
	while (++i < 4)
		window->data[index + i] = color[i];
}

int		get_pixel(t_window *window, unsigned int x, unsigned int y)
{
	int	ptr;

	ptr = *(int*)(window->data
			+ (4 * (int)window->width * ((int)window->height - 1 - y))
			+ (4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}
