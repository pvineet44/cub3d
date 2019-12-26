/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:29:09 by vparekh           #+#    #+#             */
/*   Updated: 2019/12/26 17:31:36 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_putstr(char *str)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
}

int			ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int val;
	int neg;
	int i;

	i = 0;
	val = 0;
	neg = 1;
	if (str[0] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str && str[i] && ft_isdigit(str[i]))
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * neg);
}
