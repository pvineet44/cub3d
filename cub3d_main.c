/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:23:43 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/23 09:42:17 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_prop_data		init_prop_data(t_prop_data prop_data)
{
	prop_data.map_height = 0;
	prop_data.map_width = 0;
	prop_data.h_resolution = 0;
	prop_data.v_resolution = 0;
	prop_data.f_red = 255;
	prop_data.f_green = 255;
	prop_data.f_blue = 255;
	prop_data.c_red = 0;
	prop_data.c_green = 0;
	prop_data.c_blue = 0;
	prop_data.no_texture = NULL;
	prop_data.we_texture = NULL;
	prop_data.so_texture = NULL;
	prop_data.ea_texture = NULL;
	prop_data.sprite_texture = NULL;
	return (prop_data);
}

int				validate_map(t_prop_data *prop_data)
{
	int i;
	int k;

	i = -1;
	while (++i < prop_data->map_width)
	{
		if (prop_data->map[i][0] != '1')
			return (0);
	}
	k = prop_data->map_height - 1;
	i = -1;
	while (++i < prop_data->map_width)
	{
		if (prop_data->map[i][k] != '1' || prop_data->map[i][k] != '1')
			return (0);
	}
	i = -1;
	while (++i < prop_data->map_height)
	{
		if (prop_data->map[0][i] != '1' ||\
		prop_data->map[prop_data->map_width - 1][i] != '1')
			return (0);
	}
	return (1);
}

void			invoke_error(t_prop_data prop_data, char sig)
{
	(void)prop_data;
	if (sig == 'M')
		ft_putstr("Map Error: Please check the map.\n");
	if (sig == 'A')
		ft_putstr("Argument Error: Please enter valid arguements.\n");
	exit(0);
}

t_prop_data		set_prop_data(t_prop_data prop_data, char *line)
{
	if (line[0] == '\0')
		return (prop_data);
	if (line[0] == 'R')
		prop_data = parse_resolution(&prop_data, &line[1]);
	else if (line[0] == 'N' || (line[0] == 'S' && line[1] == 'O'))
		prop_data = parse_texture(&prop_data, line[0], &line[2]);
	else if (line[0] == 'E' || line[0] == 'W')
		prop_data = parse_texture(&prop_data, line[0], &line[2]);
	else if (line[0] == 'S')
		prop_data = parse_texture(&prop_data, 'P', &line[2]);
	else if (line[0] == 'F')
		prop_data = parse_floor(&prop_data, &line[2]);
	else if (line[0] == 'C')
		prop_data = parse_ceil(&prop_data, &line[2]);
	else if (ft_isdigit(line[0]))
		prop_data = parse_map(&prop_data, &line[0]);
	else
		invoke_error(prop_data, 'A');
	ft_free_str(line);
	return (prop_data);
}

t_prop_data		cub3d_init(int fd)
{
	char		*line;
	t_prop_data prop_data;
	prop_data.map_height = 0;
	prop_data = init_prop_data(prop_data);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		prop_data = set_prop_data(prop_data, line);
	}
	if (validate_map(&prop_data) == 0)
		invoke_error(prop_data, 'M');
	return (prop_data);
}
