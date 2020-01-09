/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:53:38 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/09 15:54:00 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			loop_hook(player *player)
{
	if (player->draw)
		(player)->draw(player);
	return (1);
}

libx             *create_window(int width, int height, player *player)
{
    libx    *libx;
   	int	    config[3];
    config[0] = 32;
	config[1] = width * 4;
	config[2] = 0;

    libx = init_libx(libx);
    libx->mlx = mlx_init();
    libx->win = mlx_new_window(libx->mlx, width, height, libx->title);
    libx->surface = mlx_new_image(libx->mlx, width, height);
    libx->data = mlx_get_data_addr(libx->surface,
			&config[0], &config[1], &config[2]);
    mlx_hook(player->libx->win, 2, 1L << 0, &key_pressed, player);
	mlx_hook(player->libx->win, 3, 1L << 1, &key_released, player);
	// mlx_hook(player->libx->win, 17, 1L << 17, &program_exited, game);
	mlx_loop_hook(player->libx->mlx, &loop_hook, game);

    return(libx);
}
