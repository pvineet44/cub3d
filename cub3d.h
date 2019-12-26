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
# include <stdlib.h>
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
	char			map[100][100];
	int				map_height;
	int				map_width;
}					t_prop_data;

t_prop_data			parse_resolution(t_prop_data prop_data, char *line);
t_prop_data			parse_texture(t_prop_data prop_data, char c, char *line);
t_prop_data			parse_floor(t_prop_data prop_data, char *line);
t_prop_data			parse_ceil(t_prop_data prop_data, char *line);
t_prop_data			parse_map(t_prop_data prop_data, char *line);
void				ft_putstr(char *str);
int					ft_isspace(char c);
int					ft_isdigit(char c);
int					ft_atoi(char *str);
int					ft_free_str(char *str);

#endif
