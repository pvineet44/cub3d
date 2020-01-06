/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:17:28 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/06 13:17:30 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
libx             create_window(int width, int height)
{
    void *mlx;
    void *win;
    libx libx;

    libx.win = 0;
    libx = init_libx(libx);
    if (width == 0 || height == 0)
    {
        ft_putstr("Resolution Error. Please check the resolution arguments.\n");
        invoke_error('A');   
    }
    mlx = mlx_init();
    if (mlx == NULL)
        invoke_error('P');
    win = mlx_new_window(mlx, width, height, libx.title);
    if (win == NULL)
        invoke_error('P');
    libx.mlx = mlx;
    libx.win = win;
    return(libx);
}

point           get_direction(char direction)
{
    point   dir;
    
    if (direction == 'N')
    {
        dir.x = 0;
        dir.y = 1;
    }
    if (direction == 'E')
    {
        dir.x = 1;
        dir.y = 0;
    }
    if (direction == 'W')
    {
        dir.x = -1;
        dir.y = 0;
    }
    if (direction == 'S')
    {
        dir.x = 0;
        dir.y = -1;
    }
    else
    {
        dir.x = 0;
        dir.y = 0;
    }
    return (dir);
}
player            init_raycast(t_prop_data *prop_data)
{
    point position;
    point direction;
    point plane;
    player player;

    player.map = NULL;
    player = init_player(player);
    position.x = prop_data->posX;
    position.y = prop_data->posY;

    direction = get_direction(prop_data->direction);
    plane.x = 0;
    plane.y = 0.66;
    player.map = prop_data->map;
    player.position = position;
    player.plane = plane;
    player.direction = direction;
    return (player);
}