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

#ifndef CUB_3D_H
# define CUB_3D_H

typedef			struct			s_prop_data
{
	int		h_resolution;
	int		v_resolution;
	int		f_red;
	int		f_blue;
	int		f_green;
	int		c_red;
	int		c_blue;
	int		c_green;
	char	*no_texture;
	char	*we_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*sprite_texture;
	char	map[100][100];
	int		map_height;
	int		map_width;
}								t_prop_data;

# include <fcntl.h>

#endif
