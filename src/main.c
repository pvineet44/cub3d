/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:07:39 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:07:40 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		update(t_game *game)
{
	if (game->keys->k_right)
		rotate(game, 1);
	if (game->keys->k_left)
		rotate(game, -1);
	if (game->keys->k_up || game->keys->k_w)
		go(game, 0);
	if (game->keys->k_down || game->keys->k_s)
		go(game, 2);
	if (game->keys->k_a)
		go(game, 1);
	if (game->keys->k_d)
		go(game, 3);
	update_jump(game);
}

void		draw(t_game *game)
{
	update(game);
	mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
	clear_data(game->window);
	raycast(game->world);
	draw_ceil_ground(game);
	draw_rays(game);
	draw_sprites(game);
	draw_hud(game);
	if (game->screenshot)
		stop_game(game);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->surface, 0, 0);
}

t_window	*create_screenshot_window(t_info *info, const char *title)
{
	t_window	*res;
	int			config[3];

	if (!(res = ft_calloc(sizeof(t_window), 1)))
		return (NULL);
	config[0] = 32;
	config[1] = info->width * 4;
	config[2] = 0;
	res->width = info->width;
	res->height = info->height;
	res->title = title;
	res->mlx_ptr = info->tmp_mlx_ptr;
	res->win_ptr = NULL;
	res->surface = mlx_new_image(res->mlx_ptr, info->width, info->height);
	res->data = mlx_get_data_addr(res->surface,
			&config[0], &config[1], &config[2]);
	return (res);
}

void		take_screenshot(t_info *info)
{
	t_game *res;

	if (!(res = ft_calloc(sizeof(t_game), 1)))
		return ;
	res->world = create_world(info);
	res->screenshot = 1;
	res->keys = create_keys();
	res->draw = NULL;
	res->window = create_screenshot_window(info, "Cube3d Screenshot");
	clear_data(res->window);
	raycast(res->world);
	draw_ceil_ground(res);
	draw_rays(res);
	draw_sprites(res);
	draw_hud(res);
	stop_game(res);
}

int			main(int argc, char **argv)
{
	t_game	*game;
	t_info	*info;

	if (argc < 2 || argc > 3)
		parsing_error(NULL, 'a');
	info = parse(argv[1]);
	if (argc == 3)
	{
		if ((ft_strlen(argv[2]) == 6) && ft_strncmp(argv[2], "--save", 6) == 0)
			take_screenshot(info);
		else
			parsing_error(NULL, 'a');
	}
	game = create_game(info, "Cub3D-42");
	destroy_info(info);
	game->draw = &draw;
	start_game(game);
	stop_game(game);
	return (0);
}
