/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:24:56 by vparekh           #+#    #+#             */
/*   Updated: 2019/10/31 15:30:00 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			validate(int fd, char **line)
{
	if (fd < 0)
		return (1);
	if (line == NULL)
		return (1);
	return (0);
}

static char			*process_new_line(char *p, int value, int i, char *buffer)
{
	int j;

	j = 0;
	p = malloc(sizeof(char) * (value - i));
	if (p == NULL)
		return (0);
	i++;
	while (buffer[i] != '\0')
		p[j++] = buffer[i++];
	p[j] = '\0';
	return (p);
}

static char			*init(char *buffer, char **p, int fd)
{
	int		value;
	char	*tmp;

	value = 0;
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if ((value = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (NULL);
	buffer[value] = '\0';
	if (*p != NULL)
	{
		tmp = ft_strjoin(*p, buffer);
		ft_free(&buffer);
		ft_free(p);
		buffer = tmp;
	}
	return (buffer);
}

static int			ft_some(char **p, int value, char *buffer, char **line)
{
	int			i;

	i = 0;
	while (i < value)
	{
		if (buffer[i] == '\n')
		{
			if (!(*p = process_new_line(*p, value, i, buffer)))
				return (-1);
			if (*line == NULL)
			{
				*line = malloc(sizeof(char));
				*line[0] = '\0';
			}
			ft_free(&buffer);
			return (1);
		}
		else if (ft_free(p))
		{
			*line = ft_stradd(*line, buffer[i++]);
		}
	}
	ft_free(&buffer);
	return (2);
}

int					get_next_line(int fd, char **line)
{
	static char		*p;
	char			*buffer;
	int				value;
	int				ret;

	value = 1;
	*line = 0;
	if (validate(fd, line))
		return (-1);
	while (value > 0)
	{
		if (!(buffer = init(buffer, &p, fd)))
			return (-1);
		if ((!(value = ft_strlen(buffer))))
		{
			ft_free(&p);
			ft_free(&buffer);
			if (!(*line))
				*line = ft_strdup("");
			return (0);
		}
		if ((ret = ft_some(&p, value, buffer, line)) == 1 || ret == -1)
			return (ret);
	}
	return (1);
}
