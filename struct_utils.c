/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:33:14 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/06 13:33:16 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

libx          *init_libx(libx *libx)
{
    libx->mlx = 0;
    libx->win = 0;
    libx->title = "cu3bd";
    return (libx);
}

player          init_player(player *player)
{
    // player.map = NULL;
    // player.position = init_point(player.position);
    // player.direction = init_point(player.direction);
    // player.plane = init_point(player.plane);
    // player.rayDir = init_point(player.rayDir);
    // player.sideDist = init_point(player.sideDist);
    // player.deltaDist = init_point(player.deltaDist);
    // player.perpWallDist = 0;
    // player.cameraX = 0;
    // player.mapX = 0;
    // player.mapY = 0;
    // player.stepX = 0;
    // player.stepY = 0;
    // player.win = 0;
    // player.mlx = 0;
    // player.angle = 0.0;
    return (*player);
}