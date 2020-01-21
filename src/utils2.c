/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:05:47 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:05:48 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_jump(t_game *game)
{
	if (game->world->jump_time >= 0)
	{
		game->world->jump_time++;
		game->world->pz = (-1 * ((game->world->jump_time / 4 - 3) *
					(game->world->jump_time / 4 - 3)) + 9) * JUMP_HEIGHT;
	}
	if (game->world->jump_time >= 24)
	{
		game->world->jump_time = -1;
		game->world->pz = 0;
	}
}

void	draw_hud(t_game *game)
{
	t_rect			rect;
	unsigned char	color[4];

	set_color(color, 0, 0, 0);
	rect.width = 200;
	rect.height = 30;
	rect.x = (210 - rect.width) / 2;
	rect.y = 5;
	draw_rect(game->window, rect, color);
	set_color(color, 255, 255, 255);
	if (game->world->jump_time >= 0)
		rect.width = (24 - game->world->jump_time) / 24 * 190;
	else
		rect.width = 190;
	rect.height = 20;
	rect.x = (210 - 190) / 2;
	rect.y = 10;
	draw_rect(game->window, rect, color);
}

void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

int		get_nth_pixel_distance(t_game *game, int screen_x)
{
	int target;

	target = ((float)screen_x / (float)game->window->width) * RAYS;
	return (game->world->rays[target]->distance);
}

void	jump(t_game *game)
{
	if (game->world->jump_time == -1)
		game->world->jump_time = 0;
}
