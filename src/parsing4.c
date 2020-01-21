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

int			check_map(t_info *info)
{
	unsigned int	target;
	t_list			*ptr;

	ptr = info->map_tmp;
	target = ft_strlen(ptr->content);
	if (!check_line_ones(ptr->content))
		return (0);
	ptr = ptr->next;
	while (ptr)
	{
		if (ft_strlen(ptr->content) != target)
			return (0);
		if (((char*)ptr->content)[0] != '1' ||
				((char*)ptr->content)[target - 1] != '1')
			return (0);
		if (!ptr->next && !check_line_ones(ptr->content))
			return (0);
		ptr = ptr->next;
	}
	info->map_width = (target + 1) / 2;
	info->map_height = ft_lstsize(info->map_tmp);
	return (1);
}
