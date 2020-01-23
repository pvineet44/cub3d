/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:17:23 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:17:25 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < (int)n && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	if (i == (int)n)
	{
		return (NULL);
	}
	else
	{
		d[i] = s[i];
		return (d + i + 1);
	}
}
