/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:06:45 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:06:46 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_node(void *content)
{
	free(content);
}

void		destroy_info(t_info *info)
{
	if (info && info->map_tmp && info->map_started)
		ft_lstclear(&info->map_tmp, &destroy_node);
	free(info);
}

static void	create_map_helper(char *line, t_info *info, int x, int y)
{
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
	{
		info->px = x;
		info->py = y;
		info->orientation = *line;
	}
	else
		info->map[x][y] = ft_atoi(line);
}

void		create_map(t_info *info)
{
	int		x;
	int		y;
	t_list	*ptr;
	char	*line;

	ptr = info->map_tmp;
	info->map = ft_calloc(sizeof(int*), info->map_width);
	x = -1;
	while (++x < info->map_width)
		info->map[x] = ft_calloc(sizeof(int), info->map_height);
	y = 0;
	while (y < info->map_height)
	{
		line = ptr->content;
		x = 0;
		while (x < info->map_width)
		{
			create_map_helper(line, info, x, y);
			line += 2;
			x++;
		}
		ptr = ptr->next;
		y++;
	}
}
