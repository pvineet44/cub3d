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

#include "../cub3d.h"

libx             *create_window(int width, int height)
{
    void *mlx;
    void *win;
    libx *libx;

    libx->win = 0;
    libx = init_libx(libx);
    if (width == 0 || height == 0)
    {
        ft_putstr("Resolution Error. Please check the resolution arguments.\n");
        invoke_error('A');   
    }
    mlx = mlx_init();
    if (mlx == NULL)
        invoke_error('P');
    win = mlx_new_window(mlx, width, height, libx->title);
    if (win == NULL)
        invoke_error('P');
    libx->mlx = mlx;
    libx->win = win;
    return(libx);
}
