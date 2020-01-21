/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:20 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:06:21 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray		**create_ray_array(float angle)
{
	int		i;
	float	a;
	t_ray	**res;
	t_ray	*temp;

	if (!(res = ft_calloc(sizeof(t_ray *), RAYS)))
		return (NULL);
	i = 0;
	while (i < RAYS)
	{
		a = (-FOV / 2) + (FOV / RAYS) * i;
		temp = ft_calloc(sizeof(t_ray), 1);
		temp->angle = mod(a + angle, 360.0);
		temp->texture = NULL;
		temp->distance = INF;
		res[i] = temp;
		i += 1;
	}
	return (res);
}

void		rotate_ray_array(t_ray **rays, float angle)
{
	int i;

	i = RAYS;
	while (i--)
	{
		rays[i]->angle += angle;
		rays[i]->angle = mod(rays[i]->angle, 360.0);
	}
}

void		free_ray_array(t_ray **rays)
{
	int i;

	i = RAYS;
	while (i--)
		free(rays[i]);
	free(rays);
}

static void	draw_ray(t_game *game, t_raycasting_data data)
{
	unsigned char		color[4];

	get_pixel_color(game->world->rays[data.i]->texture,
		game->world->rays[data.i]->wall_x *
		game->world->rays[data.i]->texture->width,
		(int)floor((float)(data.a) / (float)(data.d) *
			game->world->rays[data.i]->texture->height),
		color);
	draw_pixel(game->window, data.x, data.y, color);
}

void		draw_rays(t_game *game)
{
	t_raycasting_data	data;
	int y_data = 0;
	int x_data = 0;

	data.res = ceil(game->window->width / RAYS);
	data.i = -1;
	while (++data.i < RAYS)
	{
		data.d = (int)(game->window->height /
				game->world->rays[data.i]->distance);
		data.x = data.i * data.res;
		x_data = data.x + data.res;
		y_data = (game->window->height * 0.5) - (data.d * 0.5) + game->world->pz + data.d;
		while (data.x < x_data)
		{
			data.y = (int)((game->window->height * 0.5) - (data.d * 0.5))
				+ game->world->pz;
			data.a = 0;
			while (data.y < y_data)
			{
				draw_ray(game, data);
				data.y++;
				data.a++;
			}
			data.x++;
		}
	}
}
