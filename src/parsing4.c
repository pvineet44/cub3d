/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:34 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:06:36 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line_ones(char *line)
{
	int i;

	i = 0;
	if (line[i++] != '1')
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int			calculate_length(char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while(str && str[i])
	{
		if (!ft_isspace(str[i]))
			c++;
		i++;
	}
	return (c);
}

int			check_map(t_info *info)
{
	int				target;
	t_list			*ptr;
	int				end;

	ptr = info->map_tmp;
	target = calculate_length(ptr->content);
	end = ft_strlen(ptr->content);
	if (!check_line_ones(ptr->content))
		return (0);
	ptr = ptr->next;
	while (ptr)
	{
		if (calculate_length(ptr->content) != target)
			return (0);
		if (((char*)ptr->content)[0] != '1' ||
				((char*)ptr->content)[end - 1] != '1')
			return (0);
		if (!ptr->next && !check_line_ones(ptr->content))
			return (0);
		ptr = ptr->next;
	}
	info->map_width = target;
	info->map_height = ft_lstsize(info->map_tmp);
	return (1);
}

void		check_parse(t_info *info)
{
	if (info->map_started != 2)
		parsing_error(info, 'p');
	if (info->map_started == 0)
		parsing_error(info, 'i');
	if (info->width <= 0 || info->height <= 0)
		parsing_error(info, 'a');
	if (info->texture_n == NULL || info->texture_s == NULL)
		parsing_error(info, 't');
	if (info->texture_e == NULL || info->texture_w == NULL)
		parsing_error(info, 't');
	if (info->texture_sprite == NULL)
		parsing_error(info, 'a');
	if (info->ceil[0] == 0 && info->ceil[1] == 0 && info->ceil[2] == 0)
		parsing_error(info, 'a');
	if (info->floor[0] == 0 && info->floor[1] == 0 && info->floor[2] == 0)
		parsing_error(info, 'a');
}
