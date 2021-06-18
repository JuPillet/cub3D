/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:46:42 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/23 15:46:44 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*noddel;

	if (lst && del)
	{
		noddel = lst;
		lst = lst->next;
		del(noddel->content);
		free(noddel);
	}
}
