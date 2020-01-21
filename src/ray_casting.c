/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:26 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:06:28 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycast_init(t_world *world, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (world->px - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (1 + ray->map_x - world->px) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (world->py - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (1 + ray->map_y - world->py) * ray->delta_dist_y;
	}
}

static void	raycast_while(t_world *world, t_ray *ray, int *side)
{
	while (world->map[ray->map_x][ray->map_y] != 1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			*side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			*side = 1;
		}
	}
}

static void	raycast_ray_init(t_world *world, t_ray *ray)
{
	ray->map_x = floor(world->px);
	ray->map_y = floor(world->py);
	ray->ray_dir_x = cos(deg_to_rad(ray->angle));
	ray->ray_dir_y = sin(deg_to_rad(ray->angle));
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	raycast_ray(t_world *world, t_ray *ray)
{
	int		side;

	raycast_ray_init(world, ray);
	raycast_init(world, ray);
	raycast_while(world, ray, &side);
	if (side == 0)
	{
		ray->distance = (ray->map_x - world->px +
				(1 - ray->step_x) / 2) / ray->ray_dir_x;
		ray->wall_x = world->py + ray->distance * ray->ray_dir_y;
		ray->texture = world->texture_o;
		if (ray->ray_dir_x > 0)
			ray->texture = world->texture_e;
	}
	else
	{
		ray->distance = (ray->map_y - world->py + (1 - ray->step_y) / 2) /
			ray->ray_dir_y;
		ray->wall_x = world->px + ray->distance * ray->ray_dir_x;
		ray->texture = world->texture_n;
		if (ray->ray_dir_y > 0)
			ray->texture = world->texture_s;
	}
	ray->wall_x -= floor(ray->wall_x);
}

void		raycast(t_world *world)
{
	int		i;
	float	min;

	i = -1;
	while (++i < RAYS)
	{
		min = INF;
		raycast_ray(world, world->rays[i]);
	}
}
