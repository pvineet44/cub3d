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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	if (!dst && !src)
		return (0);
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

int	key_hook(int keycode, t_mlx *ph)
{
	void *mlx = ph->mlx;
	void *win = ph->win;
	void *img = ph->img;
	int     bpp = 32;
	int     size_line  = 1600;
	int     endian = 1;
	if (img == NULL)
		img = malloc(1);
	void *new_img;
	new_img = malloc(20);
	ft_memcpy(new_img, img, 20);
	static int i = 0;
	mlx_destroy_image(mlx, img);
	i = i + 64;
	mlx_put_image_to_window(mlx, win, new_img, 50+i,50);
	return (0);
}

int main(int argc, const char *argv[])
{
	void *mlx;
	void *win;
	void *img;
	img = malloc(20);
	t_mlx pointer_holder;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "42");
	pointer_holder.mlx = mlx;
	pointer_holder.win = win;
	int width = 0;
	int height = 0;
	img = mlx_xpm_file_to_image(mlx, "test2.xpm", &width, &height);
	pointer_holder.img = img;
	mlx_key_hook(win, key_hook, &pointer_holder);
	mlx_loop(mlx);
	return 0;
}
