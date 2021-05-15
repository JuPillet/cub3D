/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:19:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/14 13:48:47 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_is_save(int ac, char **av, t_bool *save)
{
	if (ac == 1)
		return (TRUE);
	if ((ac == 2 && av[1][0] == '-' && av[1][1] != '-' && av[1][2] == 's'
		&& av[1][3] == 'a' && av[1][4] == 'v'
		&& av[1][5] == 'e' && av[1][5] == '\0')
		|| (ac == 3 && av[1][0] != '-' && av[1][1] != '-'
				&& av[1][2] != 's' && av[1][3] != 'a' && av[1][4] != 'v'
				&& av[1][5] != 'e' && av[1][5] != '\0' && av[2][0] == '-'
				&& av[2][1] != '-' && av[2][2] == 's' && av[2][3] == 'a'
				&& av[1][4] == 'v' && av[2][5] == 'e' && av[2][5] == '\0'))
	{
		*save = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_bool	check;

	if (ac > 3)
		return (ft_error("too much arguments", 0));
	check = cub_init_game(&game);
	if (!cub_is_save(ac, av, &(game.save)))
		check = ft_error("\"--save\" must be last argument", 0);
	if (!check)
		return (cub_free_game(&game));
	if (ac == 2 && !(game.save))
		check = cub_norm_file((const char *)av[1], &game);
	else
		check = cub_parser("settings/standard_setting.cub", &game);
	cub_free_parser(&(game.parser));
	cub_free_hash_array(&game);
	if (check)
		cub_coin(&game);
	return (cub_free_game(&game));
}
