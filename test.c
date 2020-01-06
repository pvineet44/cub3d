/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:26:22 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/26 18:29:05 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void		check_prop_data(t_prop_data prop_data)
{
	int i;
	int j;
	i = -1;
	j = 0;
	
	printf("h : %d\n", prop_data.h_resolution);
	printf("v : %d\n", prop_data.v_resolution);
	printf("NO: %s\n", prop_data.no_texture);
	printf("SO: %s\n", prop_data.so_texture);
	printf("EA: %s\n", prop_data.ea_texture);
	printf("WE: %s\n", prop_data.we_texture);
	printf("S: %s\n", prop_data.sprite_texture);
	printf("F: %d,%d,%d\n", prop_data.f_red, prop_data.f_green, prop_data.f_blue);
	 printf("C: %d,%d,%d\n", prop_data.c_red, prop_data.c_green, prop_data.c_blue);
	while(j < prop_data.map_height)
	{
		i = 0;
		while (i < prop_data.map_width)
		{
			write(1, &prop_data.map[i][j], 1);
			//printf("%c", prop_data.map[i][j]);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int main(int argc, const char *argv[])
{
	int fd;
	
	if (argc < 2)
	{
		ft_putstr("Map error. No Map supplied as argument\n");
		exit(0);
	}
	fd = open(argv[1],O_RDONLY);
	t_prop_data prop_data = cub3d_init(fd);
	check_prop_data(prop_data);
	//cub3d_engine(prop_data);
	//while (1);
	return 0;
}
