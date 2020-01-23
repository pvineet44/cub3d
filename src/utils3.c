/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:42:07 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/23 14:48:38 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*skip_spaces(char *line, t_info *info)
{
	while (ft_isspace(*line))
		line++;
	if (*line == ',')
		parsing_error(info, 'c');
	return (line);
}

char		*skip_digits(char *line, t_info *info)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		parsing_error(info, 'c');
	line++;
	return (line);
}
