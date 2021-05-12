/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:50:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/13 00:00:48 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_image_to_window(void *mlx, t_screen *screen)
{
	mlx_put_image_to_window(mlx, screen->mlx_screen,
		screen->pic_screen->img, 0, 0);
	return (TRUE);
}

t_bool	cub_set_parser(const char *file, t_parser *parser)
{
	parser->fd = open(file, O_RDONLY);
	parser->fd_map = open(file, O_RDONLY);
	parser->line = 0;
	parser->line_map = 0;
	if (parser->fd != -1 && parser->fd_map != -1)
		return (TRUE);
	return (cub_free_parser("cub3D failed to open", file, parser));
}

t_bool	cub_set_int(char *line, int *indln, int *value)
{
	while (line[*indln] == ' ' || line[*indln] == '\t')
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return(FALSE);
	*value = ft_atoi((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}

t_bool	cub_set_double(char *line, int *indln, double *value)
{
	while (line[*indln] != ' ' || line[*indln] == '\t')
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& (!ft_issigned(line[*indln]) || !ft_isdigit(line[(*indln) + 1])))
		return(FALSE);
	*value = ft_atof((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	if (line[*indln] == '.')
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}

void	cub_set_mlx_screen(t_game *game)
{
	game->screen->mlx_screen = mlx_new_window(game->mlx,
	*(game->screen->resolution->width), *(game->screen->resolution->height),
		"LOUIS XIV");
	game->screen->pic_screen->img = mlx_new_image(game->mlx,
	*(game->screen->resolution->width), *(game->screen->resolution->height));
	game->screen->pic_screen->addr = mlx_get_data_addr(
			game->screen->pic_screen->img,
			&(game->screen->pic_screen->bits_per_pixel),
			&(game->screen->pic_screen->line_length),
			&(game->screen->pic_screen->endian));
}
