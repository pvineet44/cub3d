/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:08:47 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:08:49 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**create_2d_array(int x, int y)
{
	int **res;

	if (!(res = ft_calloc(sizeof(int *), x)))
		return (NULL);
	while (x--)
		res[x] = ft_calloc(sizeof(int), y);
	return (res);
}

void	free_2d_array(int **array, int x)
{
	while (x--)
		free(array[x]);
	free(array);
}
