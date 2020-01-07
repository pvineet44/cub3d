/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:22:40 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/26 17:23:15 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_prop_data			parse_resolution(t_prop_data *prop_data, char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	prop_data->h_resolution = ft_atoi(&line[i]);
	i++;
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	prop_data->v_resolution = ft_atoi(&line[i]);
	return (*prop_data);
}

t_prop_data			parse_texture(t_prop_data *prop_data, char c, char *line)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (ft_isspace(line[i]))
		i++;
	tmp = &line[i];
	if (c == 'N')
		prop_data->no_texture = ft_strdup(tmp);
	else if (c == 'S')
		prop_data->so_texture = ft_strdup(tmp);
	else if (c == 'E')
		prop_data->ea_texture = ft_strdup(tmp);
	else if (c == 'W')
		prop_data->we_texture = ft_strdup(tmp);
	else if (c == 'P')
		prop_data->sprite_texture = ft_strdup(tmp);
	return (*prop_data);
}

t_prop_data			parse_floor(t_prop_data *prop_data, char *line)
{
	int i;

	i = 0;
	prop_data->f_red = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	prop_data->f_green = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	prop_data->f_blue = ft_atoi(&line[i]);
	return (*prop_data);
}

t_prop_data			parse_ceil(t_prop_data *prop_data, char *line)
{
	int i;

	i = 0;
	prop_data->c_red = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	prop_data->c_green = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	prop_data->c_blue = ft_atoi(&line[i]);
	return (*prop_data);
}

t_prop_data			parse_map(t_prop_data *prop_data, char *line)
{
	int j;
	int i;
	int k;

	k = 0;
	i = 0;
	j = prop_data->map_height;
	while (line && line[k])
	{
		if ((ft_isspace(line[k])) && (k = k + 1))
			continue;
		if (ft_isalpha(line[k]))
		{
			prop_data->posX = j;
			prop_data->posY = i;
			prop_data->direction = line[k];
			prop_data->map[i][j] = '0';
		}
		else
			prop_data->map[i][j] = line[k];
		i++;
		k++;
	}
	if (prop_data->map_width == 0)
		prop_data->map_width = i;
	prop_data->map_height++;
	return (*prop_data);
}
