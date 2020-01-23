/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:14:20 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:14:22 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *ptr;
	t_list *temp;

	(void)del;
	if (!list || !f)
		return (NULL);
	new = ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->content = f(list->content);
	ptr = new;
	while (list->next)
	{
		list = list->next;
		temp = ft_calloc(sizeof(t_list), 1);
		if (!temp)
			return (NULL);
		temp->content = f(list->content);
		ptr->next = temp;
		ptr = ptr->next;
	}
	return (new);
}
