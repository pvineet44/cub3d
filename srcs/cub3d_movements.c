/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:21:41 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/09 19:21:43 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	rotate_ray_array(t_ray **rays, float angle)
{
	int i;

	i = RAYS;
	while (i--)
	{
		rays[i]->angle += angle;
		rays[i]->angle = check_angle(rays[i]->angle, 360.0);
	}
}


void	rotate(player *player, int direction)
{
  rotate_ray_array(player->rays, direction * ROTATE_SPEED);
  player->angle += direction * ROTATE_SPEED;
  player->angle = check_angle(player->angle, 360);
}

void go(player *player, int direction)
{
    float	pos_x;
    float	pos_y;
    
    pos_x = player->prop_data->posX;
    pos_y = player->prop_data->posY;
  if (direction == 0)
	{
		player->prop_data->posX += cos(deg_to_rad(player->angle)) * PLAYER_SPEED;
		player->prop_data->posY += sin(deg_to_rad(player->angle)) * PLAYER_SPEED;
	}
  if (direction == 1)
	{
		player->prop_data->posX += cos(deg_to_rad(player->angle - 90)) * PLAYER_SPEED;
		player->prop_data->posY += sin(deg_to_rad(player->angle - 90)) * PLAYER_SPEED;
	}
  if (direction == 2)
	{
		player->prop_data->posX -= cos(deg_to_rad(player->angle)) * PLAYER_SPEED;
		player->prop_data->posY -= sin(deg_to_rad(player->angle)) * PLAYER_SPEED;
	}
  if (direction == 3)
	{
		player->prop_data->posX += cos(deg_to_rad(player->angle + 90)) * PLAYER_SPEED;
		player->prop_data->posY += sin(deg_to_rad(player->angle + 90)) * PLAYER_SPEED;
	}
  if (player->prop_data->\
  map[(int)floor(player->prop_data->posX)][(int)floor(player->prop_data->posY)])
	{
		player->prop_data->posX = pos_x;
		player->prop_data->posY = pos_y;
	}
}