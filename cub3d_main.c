/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:23:43 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/21 17:00:41 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"
#include "get_next_line.h"

t_prop_data		init_prop_data(t_prop_data prop_data)
{
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

t_prop_data			set_prop_data(t_prop_data prop_data, char *line)
{
	
}

int main(int argc, const char *argv[])
{
	int fd;
	t_prop_data prop_data;
	char *line;

	prop_data = init_prop_data(prop_data);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		prop_data = set_prop_data(prop_data, line);
	}

	return 0;
}
