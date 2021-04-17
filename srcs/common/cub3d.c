/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:19:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/18 01:09:47 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_bool	check;
	
	if (ac > 2)
		return (ft_error("too much arguments", 0));
	game = 0;
	if (mini_malloc_game(&game))
	{
		if (ac == 2)
			check = cub_norm_file((const char *)av[1], game);
		else
			check = cub_parser("setting/standard_map.cub", game);
		if (check)
			check = cub_coin(game);
	}
	else
		ft_error("insufficient memory to initiate miniRT", 0);
	mini_free_pov(&game);
	return (0);
}
