/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game.c                                       :+:      :+:    :+:   */
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
    player->posX = player->prop_data->posX;
    player->posY = player->prop_data->posY;
    return (player);
}

void            update(player *player)
{
    if (player->keys->k_right)
        rotate(player, 1);
    if (player->keys->k_left)
        rotate(player, -1);
}

void            draw(player *player)
{
    update(player);
}