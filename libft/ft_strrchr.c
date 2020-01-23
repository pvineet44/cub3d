/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:11:18 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:11:23 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	i = ft_strlen(s) - 1;
	while (i && c != s[i])
		i--;
	if (i == 0 && c == s[i])
		return ((char *)s);
	else if (i == 0 && c != s[i])
		return (NULL);
	return ((char *)s + i);
}
