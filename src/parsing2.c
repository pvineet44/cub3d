/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:52 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:06:54 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		handle_line_map(char *line, t_info *info)
{
	ft_lstadd_back(&(info->map_tmp), ft_lstnew(ft_strdup(line)));
}

void		handle_line_info(char *line, t_info *info)
{
	char type;

	type = *line;
	if (type == 'R')
		parse_resolution(line, info);
	if (type == 'N' || type == 'S' || type == 'W' || type == 'E')
		parse_texture(line, info);
	if (type == 'C' || type == 'F')
		parse_color(line, info);
}

void		parse_resolution(char *line, t_info *info)
{
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
	if (type[0] == 'N')
		info->texture_n = load_texture(info->tmp_mlx_ptr, line);
	if (type[0] == 'E')
		info->texture_e = load_texture(info->tmp_mlx_ptr, line);
	if (type[0] == 'W')
		info->texture_w = load_texture(info->tmp_mlx_ptr, line);
	if (type[0] == 'S' && type[1] == 'O')
		info->texture_s = load_texture(info->tmp_mlx_ptr, line);
	if (type[0] == 'S' && type[1] == ' ')
		info->texture_sprite = load_texture(info->tmp_mlx_ptr, line);
}

void		parse_color(char *line, t_info *info)
{
	char			type;
	unsigned char	res[3];

	type = *line;
	line += 2;
	res[0] = (unsigned char)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[1] = (unsigned char)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[2] = (unsigned char)ft_atoi(line);
	if (type == 'C')
		set_color(info->ceil, res[0], res[1], res[2]);
	else if (type == 'F')
		set_color(info->floor, res[0], res[1], res[2]);
}
