/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:01:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/23 16:01:54 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nodclear;

	while (*lst && del)
	{
		nodclear = *lst;
		*lst = (*lst)->next;
		del(nodclear->content);
		free(nodclear);
	}
}
