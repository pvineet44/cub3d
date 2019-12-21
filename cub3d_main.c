/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:23:43 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/21 18:56:59 by vparekh          ###   ########.fr       */
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

t_prop_data			parse_resolution(t_prop_data prop_data, char *line)
{
	int i;

	i = 0;
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
	return (prop_data);
}

t_prop_data			parse_texture(t_prop_data prop_data, char c, char *line)
{
	int i;
	char *tmp;

	i = 0;
	tmp = NULL;
	while (ft_isspace(line[i]))
		i++;
	tmp = &line[i];
	if (c == 'N')
		prop_data.no_texture = ft_strdup(tmp);
	else if (c == 'S')
		prop_data.so_texture = ft_strdup(tmp);
	else if (c == 'E')
		prop_data.ea_texture = ft_strdup(tmp);
	else if (c == 'W')
		prop_data.we_texture = ft_strdup(tmp);
	return (prop_data);
}

t_prop_data			set_prop_data(t_prop_data prop_data, char *line)
{
	int i;
	i = 1;
	if (line[0] == 'R')
		prop_data = parse_resolution(prop_data, &line[1]);
	else if(line[0] == 'N' || line[0] == 'S')
		prop_data = parse_texture(prop_data, line[0], &line[2]);
	else if(line[0] == 'E' || line[0] == 'W')
		prop_data = parse_texture(prop_data, line[0], &line[2]);
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

	printf("NO: %s\n", prop_data.no_texture);
	printf("SO: %s\n", prop_data.so_texture);
	printf("EA: %s\n", prop_data.ea_texture);
	printf("WE: %s\n", prop_data.we_texture);
	return 0;
}
