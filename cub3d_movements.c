/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:25:49 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/08 13:25:51 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include <stdio.h>

void rotate(int key, player *player)
{
  double  oldDirX;
  double oldPlaneX;

  oldPlaneX = player->plane.x;
  oldDirX = player->direction.x;
  float rot_angle = 1.571;
  printf("\nKey: %d\n", key);
//   if (player->prop_data->direction == 'S')
//   {
//     if (key == 123)
//       key = 124;
//     else
//       key = 123;
//   }
  //printf("dirX = %f and dirY = %f\n",player->direction.x, player->direction.y);
  if (key == 123)//left rotate
  {
    player->direction.x = (player->direction.x * cos(rot_angle)) - (player->direction.y * sin(rot_angle));
    player->direction.y = (oldDirX * sin (rot_angle)) + (player->direction.y * cos(rot_angle));
    player->plane.x = (player->plane.x * cos(rot_angle)) - (player->plane.y * sin(rot_angle));
    player->plane.y = (oldPlaneX * sin(rot_angle)) + (player->plane.y * cos(rot_angle)); 
  }
  if (key == 124)//right rotate
  {
    player->direction.x = (player->direction.x * cos(-rot_angle)) - (player->direction.y * sin(-rot_angle));
    player->direction.y = (oldDirX * sin (-rot_angle)) + (player->direction.y * cos(-rot_angle));
    player->plane.x = (player->plane.x * cos(-rot_angle)) - (player->plane.y * sin(-rot_angle));
    player->plane.y = (oldPlaneX * sin(-rot_angle)) + (player->plane.y * cos(-rot_angle)); 
  }
  printf("dirX = %f and dirY = %f\n\n",player->direction.x, player->direction.y);
  printf("positionX = %f and positionY = %f\n\n",player->position.x, player->position.y);
}

void walk(int key, player *player)
{
  float moveSpeed = 0.5;
  printf("\nKey: %d\n", key);
  if (key == 13 || key == 126)
  {
      if (player->map[(int)(player->position.x + player->direction.x * moveSpeed)][(int)(player->position.y)] == '0') 
        player->position.x += player->direction.x * moveSpeed;
      if(player->map[(int)(player->position.x)][(int)(player->position.y + player->direction.y * moveSpeed)] == '0')
          player->position.y += player->direction.y * moveSpeed;
  }
  if (key == 1 || key == 125)
  {
    if(player->map[(int)(player->position.x - player->direction.x * moveSpeed)][(int)(player->position.y)] == '0')
      player->position.x -= player->direction.x * moveSpeed;
    if(player->map[(int)(player->position.x)][(int)(player->position.y - player->direction.y * moveSpeed)] == '0')
      player->position.y -= player->direction.y * moveSpeed;
  }
    printf("dirX = %f and dirY = %f\n\n",player->direction.x, player->direction.y);
printf("positionX = %f and positionY = %f\n\n",player->position.x, player->position.y);
}


