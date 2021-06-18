/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:33:25 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/23 14:33:30 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lstcpy;
	int		lstsize;

	lstcpy = lst;
	lstsize = 0;
	while (lstcpy)
	{
		lstcpy = lstcpy->next;
		lstsize++;
	}
	return (lstsize);
}
