/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:14:04 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:14:06 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		i;
	t_list	*ptr;

	i = 0;
	if (!list)
		return (0);
	ptr = list;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
