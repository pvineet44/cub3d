/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:08:30 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:08:33 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int key, void *game)
{
	if (key == 12 || key == 53)
		stop_game(game);
	if (key == 126)
		((t_game*)game)->keys->k_up = 1;
	if (key == 125)
		((t_game*)game)->keys->k_down = 1;
	if (key == 123)
		((t_game*)game)->keys->k_left = 1;
	if (key == 124)
		((t_game*)game)->keys->k_right = 1;
	if (key == 0)
		((t_game*)game)->keys->k_a = 1;
	if (key == 2)
		((t_game*)game)->keys->k_d = 1;
	if (key == 13)
		((t_game*)game)->keys->k_w = 1;
	if (key == 1)
		((t_game*)game)->keys->k_s = 1;
	if (key == 49)
		jump(game);
	return (0);
}

int	key_released(int key, void *game)
{
	if (key == 126)
		((t_game*)game)->keys->k_up = 0;
	if (key == 125)
		((t_game*)game)->keys->k_down = 0;
	if (key == 123)
		((t_game*)game)->keys->k_left = 0;
	if (key == 124)
		((t_game*)game)->keys->k_right = 0;
	if (key == 0)
		((t_game*)game)->keys->k_a = 0;
	if (key == 2)
		((t_game*)game)->keys->k_d = 0;
	if (key == 13)
		((t_game*)game)->keys->k_w = 0;
	if (key == 1)
		((t_game*)game)->keys->k_s = 0;
	return (0);
}

int	program_exited(void *game)
{
	stop_game((t_game *)game);
	exit(0);
}
