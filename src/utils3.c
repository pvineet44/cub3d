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

float		sprite_distance(int px, int py, t_sprite *sprite)
{
	float distance;
	float sx;
	float sy;

	sx = sprite->sprite_x;
	sy = sprite->sprite_y;
	distance = sqrt((((px * px) - (sx * sx)) - ((py * py) - (sy * sy))));
	return (distance);
}

t_list		*sort_sprites(t_list *sprites, int px, int py)
{
	void		*tmp_sprite;
	t_sprite	*sp1;
	t_list		*head;

	head = sprites;
	while (head && head->next != NULL)
	{
		if (sprite_distance(px, py, sp1 = head->content) <=
		sprite_distance(px, py, head->next->content))
		{
			tmp_sprite = head->content;
			head->content = head->next->content;
			head->next->content = tmp_sprite;
		}
		head = head->next;
	}
	return (sprites);
}
