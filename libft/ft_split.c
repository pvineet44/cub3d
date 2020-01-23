/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:12:59 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:13:01 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
			len++;
		i++;
	}
	return (len);
}

static void		fill_res(char **res, const char *s, char c, int splits)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < splits)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i + k] && s[i + k] != c)
			k++;
		res[j] = ft_calloc(sizeof(char), k + 1);
		k = 0;
		while (s[i] && s[i] != c)
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		splits;

	if (!s)
		return (NULL);
	splits = count_splits(s, c);
	res = ft_calloc(sizeof(char *), splits + 1);
	if (!res)
		return (NULL);
	fill_res(res, s, c, splits);
	res[splits] = 0;
	return (res);
}
