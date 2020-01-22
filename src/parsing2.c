/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:52 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/21 18:52:12 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		handle_line_map(char *line, t_info *info)
{
	ft_lstadd_back(&(info->map_tmp), ft_lstnew(ft_strdup(line)));
}

void		handle_line_info(char *line, t_info *info)
{
	char	type;
	int		i;
	static int c;
	static int f;

	i = -1;
	type = *line;
	if (type == 'R')
		parse_resolution(line, info);
	if (type == 'N' || type == 'S' || type == 'W' || type == 'E')
		parse_texture(line, info);
	if (type == 'C' || type == 'F')
	{
		if (type == 'C' && c != 0)
			parsing_error(info, 'a');
		if (type == 'F' && f != 0)
			parsing_error(info, 'a');
		if (type == 'C')
			c++;
		if (type == 'F')
			f++;
		
		parse_color(line, info);
	}
}

void		parse_resolution(char *line, t_info *info)
{
	if (info->height != 0 || info->width != 0)
		parsing_error(info, 'a');
	line += 2;
	info->width = min(ft_atoi(line), 2560);
	while (ft_isdigit(*line))
		line++;
	info->height = min(ft_atoi(line), 1440);
}

void		parse_texture(char *line, t_info *info)
{
	char type[2];

	type[0] = line[0];
	type[1] = line[1];
	while (ft_isalpha(*line))
		line++;
	line++;
	if (type[0] == 'N' && (info->texture_n == NULL))
		info->texture_n = load_texture(info->tmp_mlx_ptr, line);
	else if (type[0] == 'E' && (info->texture_e == NULL))
		info->texture_e = load_texture(info->tmp_mlx_ptr, line);
	else if (type[0] == 'W' && (info->texture_w == NULL))
		info->texture_w = load_texture(info->tmp_mlx_ptr, line);
	else if (type[0] == 'S' && type[1] == 'O' && (info->texture_s == NULL))
		info->texture_s = load_texture(info->tmp_mlx_ptr, line);
	else if (type[0] == 'S' && type[1] == ' ' && (info->texture_sprite == NULL))
		info->texture_sprite = load_texture(info->tmp_mlx_ptr, line);
	else
		parsing_error(info, 'a');
}

void		parse_color(char *line, t_info *info)
{
	char			type;
	int				res[3];
	int				i;

	i = 0;
	type = *line;
	line += 2;
	res[0] = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[1] = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[2] = ft_atoi(line);
	while (++i < 3)
		if (res[i] < 0 || res[i] > 255)
			parsing_error(info, 'a');
	if (type == 'C')
		set_color(info->ceil, (unsigned char)res[0], (unsigned char)res[1],
		(unsigned char)res[2]);
	else if (type == 'F')
		set_color(info->floor, (unsigned char)res[0], (unsigned char)res[1],
		(unsigned char)res[2]);
}
