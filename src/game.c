/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:08:15 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:08:16 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*create_game(t_info *info, const char *title)
{
	t_game *res;

	if (!(res = ft_calloc(sizeof(t_game), 1)))
		return (NULL);
	if (info->screenshot)
		res->screenshot = 1;
	res->world = create_world(info);
	res->keys = create_keys();
	res->draw = NULL;
	res->window = create_window(info, title, res);
	return (res);
}

void		start_game(t_game *game)
{
	mlx_loop(game->window->mlx_ptr);
}

static void	init_world(t_world *res, t_info *info)
{
	res->map = info->map;
	res->mx = info->map_width;
	res->my = info->map_height;
	res->px = info->px;
	res->py = info->py;
	res->pz = 0;
	res->plane_x = (info->orientation == 'E'
		|| info->orientation == 'W' ? 0.0 : 0.40);
	res->plane_y = (info->orientation == 'E'
			|| info->orientation == 'W' ? 0.40 : 0.0);
	if (info->orientation == 'E' || info->orientation == 'S')
	{
		res->plane_x *= -1;
		res->plane_y *= -1;
	}
	res->jump_time = -1;
	res->texture_e = info->texture_e;
	res->texture_s = info->texture_s;
	res->texture_o = info->texture_w;
	res->texture_n = info->texture_n;
	res->texture_sprite = info->texture_sprite;
	res->sprites = create_sprites_array(info);
}

t_world		*create_world(t_info *info)
{
	t_world	*res;

	if (!(res = ft_calloc(sizeof(t_world), 1)))
		return (NULL);
	res->angle = 0;
	if (info->orientation == 'N')
		res->angle = -90;
	if (info->orientation == 'W')
		res->angle = 180;
	if (info->orientation == 'S')
		res->angle = 90;
	if (!(res->rays = create_ray_array(res->angle)))
		return (NULL);
	init_world(res, info);
	set_color(res->color_ceil, info->ceil[0], info->ceil[1], info->ceil[2]);
	set_color(res->color_ground, info->floor[0],
		info->floor[1], info->floor[2]);
	return (res);
}

void		stop_game(t_game *game)
{
	if (game->screenshot)
		screenshot(game);
	destroy_texture(game->window->mlx_ptr, game->world->texture_n);
	destroy_texture(game->window->mlx_ptr, game->world->texture_s);
	destroy_texture(game->window->mlx_ptr, game->world->texture_e);
	destroy_texture(game->window->mlx_ptr, game->world->texture_o);
	destroy_texture(game->window->mlx_ptr, game->world->texture_sprite);
	if (game->screenshot == 0)
		mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
	mlx_destroy_image(game->window->mlx_ptr, game->window->surface);
	free_2d_array(game->world->map, game->world->mx);
	free_ray_array(game->world->rays);
	ft_lstclear(&(game->world->sprites), &destroy_sprite);
	free(game->world);
	free(game->window);
	free(game->keys);
	free(game);
	exit(EXIT_SUCCESS);
}
