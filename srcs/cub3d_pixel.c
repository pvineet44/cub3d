/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:11:53 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/10 13:11:56 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_rect(t_prop_data *prop_data, t_rect rect, unsigned char color[4])
{
    int i;
	int j;

	i = -1;
	while (++i < rect.width)
	{
		j = -1;
		while (++j < rect.height)
			draw_pixel(prop_data, rect.x + i, rect.y + j, color);
	}
}

void    clear_data(player *player)
{
    t_rect rect;
    unsigned char color[4];

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0;
    rect.x = 0;
    rect.y = 0;
    rect.width = player->prop_data->h_resolution;
    rect.height = player->prop_data->v_resolution;
    draw_rect(player->prop_data, rect, color);
}

void    draw_pixel(player *player, unsigned int x, unsigned int y, \
unsigned char color[4])
{
    int index;
    int i;

    if (x >= player->prop_data->h_resolution || y >= player->prop_data->v_resolution)
		return ;
	index = x * 4 + y * 4 * player->prop_data->h_resolution;
	i = -1;
	while (++i < 4)
		player->libx->data[index + i] = color[i];
}
