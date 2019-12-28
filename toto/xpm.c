/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:00:48 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/27 19:38:36 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
//gcc -lmlx -framework OpenGL -framework AppKit xpm.c

typedef struct 	s_mlx
{
	void *mlx;
	void *win;
	void *img;
}				t_mlx;


int	key_hook(int keycode, t_mlx *ph)
{
	void *mlx = ph->mlx;
	void *win = ph->win;
	void *img = ph->img;
	
	static int i;
	int width = 12;
	int height = 12;

	//mlx_destroy_image(mlx, img);
	i = i + 1;
	mlx_clear_window(mlx, win);
	
	int     bpp = 0;
	int     size_line  = 0;
	int     endian = 1;

	char *c = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	printf("s: %d\n", size_line);
	printf("bpp: %d\n", bpp);
	mlx_put_image_to_window(mlx, win, img, 50+i,50);
	ph->img = img;
	return (0);
}

int main(int argc, const char *argv[])
{
	void *mlx;
	void *win;
	void *img;
	t_mlx pointer_holder;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "42");
	pointer_holder.mlx = mlx;
	pointer_holder.win = win;
	int width = 12;
	int height = 12;
	img = mlx_xpm_file_to_image(mlx, "test2.xpm", &width, &height);
	pointer_holder.img = img;
	mlx_key_hook(win, key_hook, &pointer_holder);
	mlx_loop(mlx);
	return 0;
}
