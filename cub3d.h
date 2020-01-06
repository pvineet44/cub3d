/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:07:01 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/21 16:41:57 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef	struct		s_prop_data
{
	int				h_resolution;
	int				v_resolution;
	int				f_red;
	int				f_blue;
	int				f_green;
	int				c_red;
	int				c_blue;
	int				c_green;
	char			*no_texture;
	char			*we_texture;
	char			*so_texture;
	char			*ea_texture;
	char			*sprite_texture;
	char			**map;
	char			direction;
	int				map_height;
	int				map_width;
	int				posX;
	int				posY;
}					t_prop_data;

typedef	struct		s_point
{
	double x;
	double y;
}					point;

typedef struct		s_mlx
{
	void *mlx;
	void *win;
	char *title;
}					libx;

typedef struct		s_player
{
	char **map;
	point position;
	point direction;
	point plane;
	point rayDir;
	point sideDist;
	point deltaDist;
	double perpWallDist;
	double cameraX;
	int mapX;
	int mapY;
}					player;

t_prop_data			cub3d_init(int fd);
t_prop_data			set_prop_data(t_prop_data prop_data, char *line);
t_prop_data			init_prop_data(t_prop_data prop_data);
t_prop_data			parse_resolution(t_prop_data *prop_data, char *line);
t_prop_data			parse_texture(t_prop_data *prop_data, char c, char *line);
t_prop_data			parse_floor(t_prop_data *prop_data, char *line);
t_prop_data			parse_ceil(t_prop_data *prop_data, char *line);
t_prop_data			parse_map(t_prop_data *prop_data, char *line);
player				init_player(player player);
player            	init_raycast(t_prop_data *prop_data);
point				init_point(point a);
libx				init_libx(libx libx);
libx				create_window(int width, int height);
void				invoke_error(char sig);
void				cub3d_engine(t_prop_data prop_data);
void				ft_putstr(char *str);
int					ft_isspace(char c);
int					ft_isdigit(char c);
int					ft_isalpha(int c);
int					ft_atoi(char *str);
int					ft_free_str(char *str);
int 				validate_map(t_prop_data *prop_data);

#endif