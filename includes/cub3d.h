/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:09:54 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:09:56 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define PLAYER_SPEED 0.1
# define ROTATE_SPEED 3.0
# define RAYS 200.0
# define FOV 45.0
# define JUMP_HEIGHT 10.0
# ifndef INF
#  define INF 100000000.0
# endif

typedef struct	s_rect {
	int x;
	int y;
	int width;
	int height;
}				t_rect;

typedef struct	s_raycasting_data {
	int	i;
	int	res;
	int	d;
	int	x;
	int	y;
	int	a;
}				t_raycasting_data;

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

typedef struct	s_window
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*surface;
	char			*data;
	unsigned int	width;
	unsigned int	height;
	const char		*title;
}				t_window;

typedef struct	s_texture
{
	int				width;
	int				height;
	char			*filename;
	void			*ptr;
	char			*data;
}				t_texture;

typedef struct	s_sprite
{
	int				x;
	int				y;
	float			sprite_x;
	float			sprite_y;
	float			dir_x;
	float			dir_y;
	float			inv_det;
	float			transform_x;
	float			transform_y;
	int				sprite_screen_x;
	int				sprite_width;
	int				sprite_height;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	unsigned char	color[4];
	int				texture_x;
	int				texture_y;
}				t_sprite;

typedef struct	s_ray
{
	float		angle;
	t_texture	*texture;
	float		distance;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		ray_dir_x;
	float		ray_dir_y;
	float		step_x;
	float		step_y;
	float		wall_x;
	int			map_x;
	int			map_y;
}				t_ray;

typedef struct	s_world
{
	float			angle;
	int				**map;
	t_ray			**rays;
	int				mx;
	int				my;
	float			px;
	float			py;
	float			pz;
	float			jump_time;
	t_texture		*texture_o;
	t_texture		*texture_e;
	t_texture		*texture_s;
	t_texture		*texture_n;
	t_texture		*texture_sprite;
	unsigned char	color_ceil[4];
	unsigned char	color_ground[4];
	t_list			*sprites;
	float			plane_x;
	float			plane_y;
}				t_world;

typedef struct	s_game
{
	t_window	*window;
	t_world		*world;
	t_keys		*keys;
	int			screenshot;
	void		(*draw)(struct s_game *);
}				t_game;

typedef struct	s_info
{
	void			*tmp_mlx_ptr;
	t_texture		*texture_e;
	t_texture		*texture_w;
	t_texture		*texture_n;
	t_texture		*texture_s;
	t_texture		*texture_sprite;
	t_list			*map_tmp;
	int				**map;
	int				width;
	int				height;
	int				map_width;
	int				map_height;
	int				px;
	int				py;
	char			orientation;
	unsigned char	ceil[3];
	unsigned char	floor[3];
	int				map_started;
	int				screenshot;
}				t_info;

/*
** Window management functions
*/
t_window		*create_window(t_info *info, const char *title, t_game *game);
void			close_window(t_window *window);
void			draw_rect(t_window *window, t_rect rect,
					unsigned char color[4]);
void			draw_pixel(t_window *window, unsigned int x, unsigned int y,
									unsigned char color[4]);
int				get_pixel(t_window *window, unsigned int x, unsigned int y);
void			clear_data(t_window *window);
int				key_pressed(int key, void *param);
int				key_released(int key, void *param);
int				program_exited(void *game);

/*
** Game functions
*/
t_game			*create_game(t_info *info, const char *title);
void			start_game(t_game *game);
t_ray			**create_ray_array(float angle);
t_keys			*create_keys(void);
void			rotate_ray_array(t_ray **rays, float angle);
void			free_ray_array(t_ray **rays);
void			raycast(t_world *world);
float			raycast_left(t_ray *ray, t_world *world);
float			raycast_right(t_ray *ray, t_world *world);
float			raycast_top(t_ray *ray, t_world *world);
float			raycast_bottom(t_ray *ray, t_world *world);
void			draw_rays(t_game *game);
void			stop_game(t_game *game);
int				**create_2d_array(int x, int y);
void			free_2d_array(int **array, int x);
t_world			*create_world(t_info *info);
void			draw(t_game *game);
void			rotate(t_game *game, int direction);
void			go(t_game *game, int direction);
void			draw_ceil_ground(t_game *game);
void			jump(t_game *game);
void			update_jump(t_game *game);
void			draw_hud(t_game *game);
int				screenshot(t_game *game);
void			draw_sprites(t_game *game);
t_list			*create_sprites_array(t_info *info);
void			destroy_sprite(void *content);
int				get_nth_pixel_distance(t_game *game, int screen_x);

/*
** Parsing functions
*/
t_info			*parse(char *file);
void			handle_line(char *line, t_info *info);
int				check_parsing(t_info *info);
void			parsing_error(t_info *info, char c);
void			handle_line_map(char *line, t_info *info);
void			handle_line_info(char *line, t_info *info);
void			parse_resolution(char *line, t_info *info);
void			parse_texture(char *line, t_info *info);
void			parse_color(char *line, t_info *info);
void			destroy_info(t_info *info);
int				check_map(t_info *info);
void			create_map(t_info *info);
void			check_parse(t_info *info);

/*
** Texture functions
*/
t_texture		*load_texture(void *mlx_ptr, char *filename);
void			destroy_texture(void *mlx_ptr, t_texture *texture);
void			get_pixel_color(t_texture *texture, int x, int y,
					unsigned char *result);

/*
** Utils functions
*/
float			mod(float a, float b);
float			deg_to_rad(float a);
float			dist(float a, float b, float x, float y);
void			set_color(unsigned char dest[4], unsigned char r,
					unsigned char g, unsigned char b);
int				min(int a, int b);
int				max(int a, int b);
float			minf(float a, float b);
float			maxf(float a, float b);
void			int_to_char(int n, unsigned char *src);

/*
** Debug functions
*/
void			print_ray_array(t_ray **rays);
void			print_2d_array(int **array, int x, int y);
void			fill_map_borders(int **array, int x, int y);
void			print_world(t_world *world);
void			print_info(t_info *info);
void			print_list(t_list *lst);
#endif
