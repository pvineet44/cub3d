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

void	update(t_game *game)
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

void	draw(t_game *game)
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
	if (!game->screenshot)
		mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->surface, 0, 0);
}

int		main(int argc, char **argv)
{
	t_game	*game;
	t_info	*info;

	if (argc < 2 || argc > 3)
		parsing_error(NULL, 'a');
	info = parse(argv[1]);
	if (argc == 3)
	{
		if ((ft_strlen(argv[2]) == 6) && ft_strncmp(argv[2], "--save", 6) == 0)
			info->screenshot = 1;
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
