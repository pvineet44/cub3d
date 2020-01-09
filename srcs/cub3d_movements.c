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


void	rotate(player *player, int direction)
{
  rotate_ray_array(player->rays, direction * ROTATE_SPEED);
  player->angle += direction * ROTATE_SPEED;
  player->angle = mod(player->angle, 360);
}
