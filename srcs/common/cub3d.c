/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:19:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/03 20:36:27 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_close_cub(t_game *game)
{
	exit(cub_free_game(game));
}

t_bool	cub_bmp_save(char *c_bm, short *s_bm, int *i_bm, t_game *game)
{
	int	save_fd;
	int	paint;

	save_fd = open("./bmp_save/cub3D_save.bmp",
		O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (save_fd == -1)
		return (FALSE);
	write(save_fd, c_bm, 2);
	write(save_fd, i_bm, 4);
	write(save_fd, s_bm, 4);
	write(save_fd, (i_bm + 1), 16);
	write(save_fd, (s_bm + 2), 4);
	write(save_fd, (i_bm + 5), 24);
	while (game->screen.resolution.height--)
	{
		paint = -1;
		while (++paint < game->screen.resolution.width)
			write(save_fd, (game->screen.pic_screen.addr+ (
					game->screen.resolution.height
					* (game->screen.pic_screen.line_length)) + (paint * 4)), 4);
	}
	close(save_fd);
	return (TRUE);
}

t_bool	cub_bmp_init(t_game *game)
{
	char	c_bm[2];
	short	s_bm[4];
	int		i_bm[11];

	c_bm[0] = 'B';
	c_bm[1] = 'M';
	i_bm[0] = sizeof(c_bm) + sizeof(s_bm) + sizeof(i_bm) + (
		(game->screen.resolution.height * game->screen.resolution.width) * 4);
	s_bm[0] = 0;
	s_bm[1] = 0;
	i_bm[1] = sizeof(c_bm) + sizeof(s_bm) + sizeof(i_bm);
	i_bm[2] = sizeof(s_bm) - 4 + sizeof(i_bm) - 8;
	i_bm[3] = game->screen.resolution.width;
	i_bm[4] = game->screen.resolution.height;
	s_bm[2] = 1;
	s_bm[3] = 32;
	i_bm[5] = 0;
	i_bm[6] = 0;
	i_bm[7] = 0;
	i_bm[8] = 0;
	i_bm[9] = 0;
	i_bm[10] = 0;
	return (cub_bmp_save(c_bm, s_bm, i_bm, game));
}

t_bool	cub_is_save(int ac, char **av, t_game *game)
{
	game->save = FALSE;
	if (ac == 2)
		return (TRUE);
	if ((ac == 3 && av[2][0] == '-' && av[2][1] == '-' && av[2][2] == 's'
		&& av[2][3] == 'a' && av[2][4] == 'v'
		&& av[2][5] == 'e' && av[2][6] == '\0'))
	{
		game->save = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_bool	check;

	if (ac == 1)
		return (ft_error("One first argument expected. It must be a map \
settings file with \".cub\" extention", 0));
	if (ac > 3)
		return (ft_error("too much arguments", 0));
	if (!cub_is_save(ac, av, &(game)))
		return (ft_error("\"--save\" must be second and last argument \
if you want save the first cub3D frame.", 0));
	if (!(cub_init_game(&game)))
		return (cub_free_game(&game));
	check = cub_norm_file((const char *)av[1], &game);
	cub_free_parser(&(game.parser));
	cub_free_hash_array(&game);
	if (check)
		cub_coin(&game);
	return (cub_free_game(&game));
}
