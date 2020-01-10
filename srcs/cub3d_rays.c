/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:27:39 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/10 13:27:41 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void raycast_init(t_prop_data *prop_data, t_ray *ray)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (prop_data->posX - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
		ray->side_dist_x = (1 + ray->map_x - prop_data->posX) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
		ray->side_dist_y = (prop_data->posY - ray->map_y) * ray->delta_dist_y;
    }
    else
	{
		ray->step_y = 1;
		ray->side_dist_y = (1 + ray->map_y - prop_data->posY) * ray->delta_dist_y;
	}
}

static void raycast_while(t_prop_data *prop_data, t_ray *ray, int *side)
{
    while (prop_data->map[ray->map_x][ray->map_y] != '1')
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x +=ray->delta_dist_x;
            ray->map_x += ray->step_x;
            *side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            *side = 0;
        }
    }
}

static void	raycast_ray(t_prop_data *prop_data, t_ray *ray)
{
	int		side;

	ray->map_x = floor(prop_data->posX);
	ray->map_y = floor(prop_data->posY);
	ray->ray_dir_x = cos(deg_to_rad(ray->angle));
	ray->ray_dir_y = sin(deg_to_rad(ray->angle));
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	raycast_init(prop_data, ray);
	raycast_while(prop_data, ray, &side);
	if (side == 0)
	{
		ray->distance = (ray->map_x - prop_data->posX + (1 - ray->step_x) / 2) / ray->ray_dir_x;
		ray->wall_x = prop_data->posY + ray->distance * ray->ray_dir_y;
		ray->texture = prop_data->we_texture;
		if (ray->ray_dir_x > 0)
			ray->texture = prop_data->ea_texture;
	}
  else
	{
		ray->distance = (ray->map_y - prop_data->posY + (1 - ray->step_y) / 2) / ray->ray_dir_y;
		ray->wall_x = prop_data->posX + ray->distance * ray->ray_dir_x;
		ray->texture = prop_data->no_texture;
		if (ray->ray_dir_y > 0)
			ray->texture = prop_data->so_texture;
	}
	ray->wall_x -= floor(ray->wall_x);
}

void       raycast(player *player)
{
    int	i;
	float	min;

	i = -1;
	while (++i < RAYS)
	{
		min = INF;
		raycast_ray(player->prop_data, player->rays[i]);
	}
}