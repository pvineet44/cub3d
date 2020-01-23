/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:13:47 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:13:49 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *buffer;

	buffer = ft_calloc(sizeof(char), ft_strlen(src));
	ft_memcpy(buffer, src, n);
	ft_memcpy(dest, buffer, n);
	return (dest);
}
