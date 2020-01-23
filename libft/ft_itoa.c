/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:15:31 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:15:32 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_n_in_ptr(char *ptr, int n, int len)
{
	int i;

	if (n == 0 && len == 1)
	{
		ptr[0] = '0';
		return ;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		ft_n_in_ptr(ptr, -n, len);
		return ;
	}
	i = len - 1;
	while (ptr[i])
		i--;
	ptr[i] = '0' + n % 10;
	if (n / 10)
		ft_n_in_ptr(ptr, n / 10, len);
}

static int	ft_get_number_length(int n)
{
	int len;

	if (n <= -2147483648)
		return (11);
	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_get_number_length(n);
	res = ft_calloc(sizeof(char), len + 1);
	if (n <= -2147483648)
	{
		res = ft_calloc(sizeof(char), 12);
		ft_memcpy(res, "-2147483648", 11);
		return (res);
	}
	ft_n_in_ptr(res, n, len);
	return (res);
}
