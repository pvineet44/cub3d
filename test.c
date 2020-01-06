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
	printf("posX: %d\n", prop_data.posX);
	printf("posY: %d\n", prop_data.posY);
	printf("direction: %c\n", prop_data.direction);
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

void		check_player_data(player player, t_prop_data prop_data)
{	
	int i;
	int j;
	i = -1;
	j = 0;
	printf("position(x,y): %f,%f\n", player.position.x, player.position.y);
	printf("direction(x,y): %f,%f\n", player.direction.x, player.direction.y);
	printf("plane(x,y): %f,%f\n", player.plane.x, player.plane.y);
	printf("rayDir(x,y): %f,%f\n", player.rayDir.x, player.rayDir.y);
	printf("sideDist(x,y): %f,%f\n", player.sideDist.x, player.sideDist.y);
	printf("deltaDist(x,y): %f,%f\n", player.deltaDist.x, player.deltaDist.y);
	printf("perpWallDist: %f\n", player.perpWallDist);
	printf("cameraX: %f\n", player.cameraX);
	printf("map(x,y): %d,%d\n", player.mapX, player.mapY);

	while(j < prop_data.map_height)
	{
		i = 0;
		while (i < prop_data.map_width)
		{
			write(1, &player.map[i][j], 1);
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
	t_prop_data prop_data = cub3d_init(fd); // call it parse
	//check_prop_data(prop_data);
	libx libx;
	 libx = create_window(prop_data.h_resolution, prop_data.v_resolution);
	 player player;
	 player = init_raycast(&prop_data);
	 //check_player_data(player, prop_data);
	 draw_scene(&prop_data, &player, &libx);
	 mlx_loop(libx.mlx);
	//cub3d_raycast(prop_data);
	//while (1);
	return 0;
}
