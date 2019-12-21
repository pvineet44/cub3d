/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:14:21 by vparekh           #+#    #+#             */
/*   Updated: 2019/10/30 16:27:18 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_free(char **str)
{
	if (!str || !*str)
		return (1);
	free(*str);
	*str = 0;
	return (1);
}

int				ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		copy[j] = s1[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*strj;

	i = -1;
	j = -1;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strdup(s1));
	strj = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!strj)
		return (0);
	while (s1[++i] != '\0')
		strj[i] = s1[i];
	while (s2[++j] != '\0')
	{
		strj[i] = s2[j];
		i++;
	}
	strj[i] = '\0';
	return (strj);
}

char			*ft_stradd(char *str, char ch)
{
	char		*res;
	int			len;
	int			i;

	res = NULL;
	len = str ? ft_strlen(str) : 0;
	len = len + 2;
	res = (char*)malloc(sizeof(char) * (len));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (str && str[++i])
		res[i] = str[i];
	res[len - 2] = ch;
	res[len - 1] = 0;
	ft_free(&str);
	return (res);
}
