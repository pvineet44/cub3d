/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:36:17 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/09 19:36:18 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	check_angle(float a, float b)
{
	a -= b * fabs((float)((int)(a / b)));
	if (a >= 0)
		return (a);
	return (a + b);
}

float	deg_to_rad(float a)
{
	return (a / 360 * (2 * M_PI));
}

