/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:02 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:06:03 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_texture	*load_texture(void *mlx_ptr, char *filename)
{
	t_texture	*res;
	int			config[3];

	res = ft_calloc(sizeof(t_texture), 1);
	res->ptr = mlx_xpm_file_to_image(mlx_ptr, filename,
			&(res->width), &(res->height));
	if (!res->ptr)
		return (res);
	config[0] = 32;
	config[1] = res->width * 4;
	config[2] = 0;
	res->data = mlx_get_data_addr(res->ptr,
			&config[0], &config[1], &config[2]);
	return (res);
}

void		destroy_texture(void *mlx_ptr, t_texture *texture)
{
	mlx_destroy_image(mlx_ptr, texture->ptr);
	free(texture);
}

void		get_pixel_color(t_texture *texture, int x, int y,
		unsigned char *result)
{
	int index;
	int i;

	if (x >= texture->width || y >= texture->height)
		return ;
	if (x < 0 || y < 0)
		return ;
	index = (x + y * texture->width) * 4;
	i = -1;
	while (++i < 4)
		result[i] = texture->data[index + i];
}
