/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:05:54 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/23 16:36:21 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_color(unsigned char color[4], unsigned char r, unsigned char g,
		unsigned char b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = 0;
}

void		rotate(t_game *game, int direction)
{
	float temp;

	temp = game->world->plane_x;
	game->world->plane_x = game->world->plane_x * cos(-deg_to_rad(direction *
				ROTATE_SPEED)) - game->world->plane_y *
		sin(-deg_to_rad(direction * ROTATE_SPEED));
	game->world->plane_y = temp * sin(-deg_to_rad(direction * ROTATE_SPEED)) +
		game->world->plane_y * cos(-deg_to_rad(direction * ROTATE_SPEED));
	rotate_ray_array(game->world->rays, direction * ROTATE_SPEED);
	game->world->angle += direction * ROTATE_SPEED;
	game->world->angle = mod(game->world->angle, 360);
}

static void	go_helper(t_game *game, int direction)
{
	if (direction == 0)
	{
		game->world->px += cos(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
		game->world->py += sin(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
	}
	if (direction == 1)
	{
		game->world->px += cos(deg_to_rad(game->world->angle - 90))
			* PLAYER_SPEED;
		game->world->py += sin(deg_to_rad(game->world->angle - 90))
			* PLAYER_SPEED;
	}
	if (direction == 2)
	{
		game->world->px -= cos(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
		game->world->py -= sin(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
	}
	if (direction == 3)
	{
		game->world->px += cos(deg_to_rad(game->world->angle + 90)) *
			PLAYER_SPEED;
		game->world->py += sin(deg_to_rad(game->world->angle + 90)) *
			PLAYER_SPEED;
	}
}

void		go(t_game *game, int direction)
{
	float	pos_x;
	float	pos_y;

	pos_x = game->world->px;
	pos_y = game->world->py;
	go_helper(game, direction);
	if ((game->world->map[(int)floor(game->world->px)]
			[(int)floor(game->world->py)] == 1) || \
			((game->world->map[(int)floor(game->world->px)]
			[(int)floor(game->world->py)] == 2)))
	{
		game->world->px = pos_x;
		game->world->py = pos_y;
	}
}

void		draw_ceil_ground(t_game *game)
{
	t_rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.height = game->window->height / 2 + game->world->pz;
	rect.width = game->window->width;
	draw_rect(game->window, rect, game->world->color_ceil);
	rect.y = rect.height;
	draw_rect(game->window, rect, game->world->color_ground);
}
