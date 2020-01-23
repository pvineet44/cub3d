/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:14:34 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:14:36 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void *))
{
	t_list *ptr;

	if (!f || !list)
		return ;
	ptr = list;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
