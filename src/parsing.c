/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:07:10 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/23 16:07:49 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*parse(char *file)
{
	t_info	*res;
	int		fd;
	int		status;
	char	*line;

	fd = open(file, O_RDONLY);
	res = ft_calloc(sizeof(t_info), 1);
	if (fd < 0)
		parsing_error(res, 'f');
	res->tmp_mlx_ptr = mlx_init();
	while ((status = get_next_line(fd, &line)) > 0)
	{
		handle_line(line, res);
		free(line);
	}
	handle_line(line, res);
	free(line);
	if (!check_parsing(res))
		parsing_error(res, 'm');
	create_map(res);
	return (res);
}

void	handle_line(char *line, t_info *info)
{
	if (*line == '\0')
	{
		return ;
	}
	if (!ft_isdigit(*line) && info->map_started)
		parsing_error(info, 'm');
	if (ft_isdigit(*line))
	{
		info->map_started = 1;
		handle_line_map(line, info);
	}
	else
		handle_line_info(line, info);
}

int		check_parsing(t_info *info)
{
	if (info->map_started == 1 && !check_map(info))
		return (0);
	return (1);
}

void	parsing_error(t_info *info, char c)
{
	destroy_info(info);
	write(1, "Error\n", 6);
	if (c == 'a')
		write(1, "Invalid args\n", 14);
	else if (c == 'c')
		write(1, "Invalid color in ceil or floor\n", 32);
	else if (c == 'm')
		write(1, "Invalid map\n", 13);
	else if (c == 'f')
		write(1, "Can't open file\n", 17);
	else if (c == 'i')
		write(1, "Map missing in cub\n", 20);
	else if (c == 'p')
		write(1, "Player missing in cub\n", 23);
	else if (c == 'r')
		write(1, "Two player positions in cub\n", 29);
	else if (c == 't')
		write(1, "Problem in texture\n", 18);
	else
		write(1, "Error in cub3d\n", 16);
	exit(0);
}
