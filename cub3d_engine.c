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
#include <stdio.h>

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
    else if (direction == 'E')
    {
        dir.x = 1;
        dir.y = 0;
    }
    else if (direction == 'W')
    {
        dir.x = -1;
        dir.y = 0;
    }
    else if (direction == 'S')
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

player         *calculate_step_dist(player *player)
{
    if (player->rayDir.x < 0)
    {
        player->stepX = -1;
        player->sideDist.x = (player->position.x - player->mapX) * player->deltaDist.x;
    }
    else
    {
        player->stepX = 1;
        player->sideDist.x = (player->mapX + 1.0 - player->position.x) * player->deltaDist.x;
    }
    if (player->rayDir.y < 0)
    {
        player->stepY = -1;
        player->sideDist.y = (player->position.y - player->mapY) * player->deltaDist.y;
    }
    else
    {
        player->stepY = 1;
        player->sideDist.y = (player->mapY + 1.0 - player->position.y) * player->deltaDist.y;
    }      
    return (player);
}
player         *set_sideDist(player *player, char c)
{
    if (c == 'x')
    {
        player->sideDist.x += player->deltaDist.x;
        player->mapX += player->stepX;
    }
    if (c == 'y')
    {
        player->sideDist.y += player->deltaDist.y;
        player->mapY += player->stepY;
    }

    return (player);
}
player         *perform_dda(player *player)
{
    int hit;
    int side;

    side = 0;
    hit = 0;
    while (hit == 0)
    {
        if (player->sideDist.x < player->sideDist.y)
            set_sideDist(player, 'x');
        else
        {
            set_sideDist(player, 'y');
            side = 1;
        }
            
        if (player->map[player->mapX][player->mapY] > 0)
            hit = 1;
    }
    if (side == 0)
        player->perpWallDist = (player->mapX - player->position.x + (1 - player->stepX) / 2) / player->rayDir.x;
    else
        player->perpWallDist = (player->mapY - player->position.y + (1 - player->stepY) / 2) / player->rayDir.y;
    //     printf("player->perpWallDist: %f\n", player->perpWallDist);
    //    printf("mapX: %d \t position.X: %f \t stepX: %d \t rayDirX: %f\n", player->mapX, player->position.x, player->stepX, player->rayDir.x);
    //    printf("mapY: %d \t position.Y: %f \t stepY: %d \t rayDirY: %f\n", player->mapY, player->position.y, player->stepY, player->rayDir.y);

    
    // printf("lineHeight: %d\n", lineHeight);
    return (player);
}

void           draw_column(int x, int drawStart, int drawEnd, libx *libx)
{
    int R = 251;
    int G = 247;
    int B = 3;
    int A = 1;
    int bpp;
    int endian;
    int size_line;
    int height = drawEnd - drawStart;
    char *img = mlx_new_image(libx->mlx, 1, height);
    char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    char *tmp = img_data;
    int pix = 4 * height;
    int c = 0;
//    printf("c: %d \t ds: %d \t de: %d \t h: %d\n", x, drawStart, drawEnd, height);
//   printf("A: %d\n", A);
    while (c < pix)
    {
        *tmp++ = R;
        *tmp++ = G;
        *tmp++ = B;
        *tmp++ = A;
        c += 4;
    }
    mlx_put_image_to_window(libx->mlx, libx->win, img, x, drawStart);
}

player         *render_image(t_prop_data *prop_data, player *player, libx *libx, int column)
{
    int lineHeight;
    int drawStart;
    int drawEnd;
    
    lineHeight= (int)(2 * prop_data->v_resolution / player->perpWallDist);
    drawStart = -lineHeight / 2 + prop_data->v_resolution / 2;
    if (drawStart < 0)
        drawStart = 0;
    drawEnd = lineHeight / 2 + prop_data->v_resolution / 2;
    if (drawEnd >= prop_data->v_resolution)
        drawEnd = prop_data->v_resolution - 1;
    
    if (player->map[player->mapX][player->mapY] > 0)
        draw_column(column, drawStart, drawEnd, libx);
    return (player);
}

void           draw_scene(t_prop_data *prop_data, player *player, libx *libx)
{
    double i;

    i = 0;
    while(i < prop_data->h_resolution)
    {
        // printf("prop_data->h_resolution: %d\t i:%f\n", prop_data->h_resolution, i);
        player->cameraX = 2 * i / (prop_data->h_resolution) - 1;
        player->rayDir.x = player->direction.x + (player->plane.x * player->cameraX);
        player->rayDir.y = player->direction.y + (player->plane.y * player->cameraX);
        
        player->mapX = (int)player->position.x;
        player->mapY = (int)player->position.y;
        player->deltaDist.x = fabs(1/player->rayDir.x);
        player->deltaDist.y = fabs(1/player->rayDir.y);
        player = calculate_step_dist(player);
        printf("mapX: %d \t position.X: %f \t deltaDistX %f \t sideDistX %f\n", player->mapX, player->position.x, player->deltaDist.x, player->sideDist.x);
        printf("mapY: %d \t position.Y: %f \t deltaDistY %f \t sideDistY %f\n", player->mapY, player->position.y, player->deltaDist.y, player->sideDist.y);
        player = perform_dda(player);
        player = render_image(prop_data, player, libx, i);
        i++;
    }
}