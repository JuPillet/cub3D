/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:58:13 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/18 13:58:15 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		strind;
	int		posinega;
	int		result;

	strind = 0;
	posinega = 1;
	while (str[strind] == ' ' || (str[strind] >= 9 && str[strind] <= 13))
		strind++;
	if (str[strind] == '-')
		posinega = -1;
	if (!(str[strind] == '-') && !(str[strind] == '+'))
		strind--;
	result = 0;
	while (str[++strind] >= '0' && str[strind] <= '9')
		result = (result * 10) + ((str[strind] - '0') * posinega);
	return (result);
}
