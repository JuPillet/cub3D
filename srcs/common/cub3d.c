/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:19:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/05 23:55:12 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_bool	check;
	
	if (ac > 3)
		return (ft_error("too much arguments", 0));
	game = 0;
	if (cub_malloc_game(&game))
	{
		if (ac == 2)
			check = cub_norm_file((const char *)av[1], game);
		else
			check = cub_parser("settings/standard_setting.cub", game);
//		if (check)
//			check = cub_coin(game);
	}
	cub_free_game(&game);
	return (0);
}
