/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:11:08 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:11:09 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			in_charset(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t		trim_length(char const *s1, char const *set)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s1[i] && in_charset(set, s1[i]))
		i++;
	if (i == (int)ft_strlen(s1))
		return (0);
	len = ft_strlen(s1) - i;
	i = ft_strlen(s1) - 1;
	while (i && in_charset(set, s1[i]))
	{
		i--;
		j++;
	}
	len -= j;
	return (len);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*res;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	len = trim_length(s1, set);
	if (!len)
		return (ft_calloc(sizeof(char), 1));
	res = ft_calloc(sizeof(char), len + 1);
	while (in_charset(set, s1[i]))
		i++;
	while (j < len)
	{
		res[j] = s1[i + j];
		j++;
	}
	return (res);
}
