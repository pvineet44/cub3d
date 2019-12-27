/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:39:20 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/26 18:43:00 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -lmlx -framework OpenGL -framework AppKit test.c

#include "mlx.h"



int main(int argc, char const *argv[])
{
	void *mlx;
	void *win;
	void *img;
	void *img2;

	int     bpp = 32;
	int     size_line  = 1600;
	int     endian = 1;

	int i = 0;
	mlx = mlx_init(); 
	win = mlx_new_window(mlx,800,600,"42");
	
	img = mlx_new_image(mlx, 200,200);
	char    *img_data =  mlx_get_data_addr(img, &bpp, &size_line, &endian);
	char *tmp = img_data + 0;
	int c = 1;
	while (i < (160000))
	{
			*tmp++ = 102;
			*tmp++ = 255;
			*tmp++ = 255;
			*tmp++ = 1;
			i = i + 4;
	}
	i = 200;
	while (i < 400)
	{
		mlx_pixel_put(mlx, win, i,i,0x66FFFF);
		i++;
	}
	i = 0;
	int j = 0;
	while (j < 200)
	{
		i = 0;
		while (i < 400)
		{
			mlx_pixel_put(mlx, win, i+j,i+200,0xff00ff);
			i++;
		}
		j++;
	}
	i = 0;
	j = 0;
	while (j < 200)
	{
		i = 0;
		while (i < 400)
		{
			mlx_pixel_put(mlx, win, i+200,i+j,0xff00ff);
			i++;
		}
		j++;
	}
	
	mlx_put_image_to_window(mlx, win, img, 0,0);
	img2 = mlx_new_image(mlx, 200,200);
	char    *img_data2 =  mlx_get_data_addr(img2, &bpp, &size_line, &endian);

	char *tmp2 = img_data2 + 0;
	while (i < (160000))
	{
			*tmp2++ = 102;
			*tmp2++ = 255;
			*tmp2++ = 255;
			*tmp2++ = 1;
			i = i + 4;
	}
	mlx_put_image_to_window(mlx, win, img2, 400,400);
	mlx_loop(mlx);
	return 0;
}