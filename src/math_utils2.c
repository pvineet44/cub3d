/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:07:19 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:07:21 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
