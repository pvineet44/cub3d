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

typedef struct		s_ray
{
	float			angle;
	char			texture;
	float			distance;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			ray_dir_x;
	float			ray_dir_y;
	float			step_x;
	float			step_y;
	int				map_x;
	int				map_y;
}					ray;

typedef struct	s_keys {
	int k_up;
	int k_down;
	int k_left;
	int k_right;
	int k_a;
	int k_s;
	int k_d;
	int k_w;
}				t_keys;

typedef struct		s_libx
{
	void 			*mlx;
	void 			*win;
	char 			*title;
	void 			*surface;
	char			*data;
	unsigned int	width;
	unsigned int	height;
	const char		*title;

}					libx;

typedef struct		s_player
{
	ray			**rays;
	float angle;
	double perpWallDist;
	double cameraX;
	int mapX;
	int mapY;
	int posX;
	int posY;
	libx *libx;
	t_prop_data *prop_data;
	t_keys *keys;
}					player;

t_prop_data			cub3d_init(int fd);
t_prop_data			set_prop_data(t_prop_data prop_data, char *line);
t_prop_data			init_prop_data(t_prop_data prop_data);
t_prop_data			parse_resolution(t_prop_data *prop_data, char *line);
t_prop_data			parse_texture(t_prop_data *prop_data, char c, char *line);
t_prop_data			parse_floor(t_prop_data *prop_data, char *line);
t_prop_data			parse_ceil(t_prop_data *prop_data, char *line);
t_prop_data			parse_map(t_prop_data *prop_data, char *line);
player         		*render_image(t_prop_data *prop_data, player *player, int column);
player				*perform_dda(player *player);
player    		    *set_sideDist(player *player, char c);
player        	 	*calculate_step_dist(player *player);
player   	        *init_raycast(t_prop_data *prop_data, player *player);
player				init_player(player *player);
libx		        *init_libx(libx *libx);
libx				*create_window(int width, int height);
player    		    *create_game(player *player);
void				draw_scene(t_prop_data *prop_data, player *player);
void				invoke_error(char sig);
void				cub3d_engine(t_prop_data prop_data);
void				ft_putstr(char *str);
void           		draw_column(int x, int drawStart, int drawEnd, player *player);
void				rotate(int key, player *player);
void 				walk(int key, player *player);
int					ft_isspace(char c);
int					ft_isdigit(char c);
int					ft_isalpha(int c);
int					ft_atoi(char *str);
int					ft_free_str(char *str);
int					key_hook(int key,player *player);
int 				validate_map(t_prop_data *prop_data);

#endif