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

libx             *create_window(int width, int height)
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
    return(libx);
}
