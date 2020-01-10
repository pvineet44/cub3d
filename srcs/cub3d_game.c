/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:32:43 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/09 15:32:46 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

player          *set_direction(player *player)
{
    if (player->prop_data->direction == 'N')
        player->angle = -90;
    if (player->prop_data->direction == 'W')
        player->angle = 180;
    if (player->prop_data->direction == 'S')
        player->angle = 90;
    return (player);
}
player          *create_game(player *player)
{
    player = set_direction(player);
    return (player);
}

void            update(player *player)
{
   if (player->keys->k_right)
		rotate(player, 1);
	if (player->keys->k_left)
		rotate(player, -1);
	if (player->keys->k_up || player->keys->k_w)
		go(player, 0);
	if (player->keys->k_down || player->keys->k_s)
		go(player, 2);
	if (player->keys->k_a)
		go(player, 1);
	if (player->keys->k_d)
		go(player, 3);
        (void)player;

}
