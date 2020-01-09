/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:09:31 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/09 19:09:33 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_pressed(int key, player *player)
{
//   if (key == 12 || key == 53)
// 		stop_player(player);
  if (key == 126)
    player->keys->k_up = 1;
  if (key == 125)
    player->keys->k_down = 1;
  if (key == 123)
    player->keys->k_left = 1;
  if (key == 124)
    player->keys->k_right = 1;
  if (key == 0)
    player->keys->k_a = 1;
  if (key == 2)
    player->keys->k_d = 1;
  if (key == 13)
    player->keys->k_w = 1;
  if (key == 1)
      player->keys->k_s = 1;
//   if (key == 49)
//       jump(player);
  return (0);
}

int key_released(int key, player *player)
{
  if (key == 126)
    player->keys->k_up = 0;
  if (key == 125)
    player->keys->k_down = 0;
  if (key == 123)
    player->keys->k_left = 0;
  if (key == 124)
    player->keys->k_right = 0;
  if (key == 0)
    player->keys->k_a = 0;
  if (key == 2)
    player->keys->k_d = 0;
  if (key == 13)
    player->keys->k_w = 0;
  if (key == 1)
    player->keys->k_s = 0;
  return (0);
}

// int program_exited(void *player)
// {
//   stop_player((t_player *)player);
//   exit(0);
// }