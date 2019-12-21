/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:23:43 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/21 18:29:47 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"
#include "get_next_line.h"
#include <stdio.h>

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

int			ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int				ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				ft_atoi(char *str)
{
	int val;
	int neg;
	int i;

	i = 0;
	val = 0;
	neg = 1;
	if (str[0] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str &&str[i] && ft_isdigit(str[i]))
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * neg);
}

t_prop_data			set_prop_data(t_prop_data prop_data, char *line)
{
	int i;
	i = 1;
	if (line[0] == 'R')
	{
		while (ft_isspace(line[i]))
			i++;
		prop_data.h_resolution = ft_atoi(&line[i]);
		i++;
		while (ft_isdigit(line[i]))
			i++;
		while (ft_isspace(line[i]))
			i++;
		prop_data.v_resolution = ft_atoi(&line[i]);
		printf("h : %d\n", prop_data.h_resolution);
		printf("v : %d\n", prop_data.v_resolution);
	}
	return prop_data;
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
