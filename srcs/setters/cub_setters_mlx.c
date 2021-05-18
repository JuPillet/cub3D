/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:30:39 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/17 17:39:14 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_set_my_mlx_pixel(t_img_data data, int x, int y, int color)
{
	char	*dst;

	dst = data.addr + ((y * data.line_length)
			+ (x * (data.bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

t_bool	cub_set_texture(t_game *game, t_parser *parser,
	char *path, void **texture)
{
	int	width;
	int	height;

	parser->indln = 0;
	*texture = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	free(path);
	if (!(*texture))
		return (ft_error("program can't open texture", parser->line));
	if (width != SIDE || height != SIDE)
		return (ft_error("wrong texture height or width must be 64 * 64 pixel",
				parser->line));
	return (TRUE);
}

int	cub_set_image_to_window(t_game *game)
{
	void	*mlx;
	void	*mlx_screen;
	void	*img;

	mlx = game->mlx;
	mlx_screen = game->screen.mlx_screen;
	img = game->screen.pic_screen.img;
	cub_render(game);
	mlx_put_image_to_window(mlx, mlx_screen, img, 0, 0);
	return (TRUE);
}

void	cub_set_mlx_screen(t_game *game)
{
	t_screen		*screen;
	t_img_data		*pic_screen;
	t_resolution	resolution;

	screen = &(game->screen);
	pic_screen = &(screen->pic_screen);
	resolution = game->screen.resolution;
	screen->mlx_screen = mlx_new_window(game->mlx,
			resolution.width, resolution.height, "LOUIS XIV");
	pic_screen->img = mlx_new_image(game->mlx,
			resolution.width, resolution.height);
	pic_screen->addr = mlx_get_data_addr(
			screen->pic_screen.img, &(pic_screen->bits_per_pixel),
			&(pic_screen->line_length), &(pic_screen->endian));
}
