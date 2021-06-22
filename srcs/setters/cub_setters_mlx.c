/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:30:39 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 16:51:40 by jpillet          ###   ########.fr       */
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
	char *path, t_img_data *texture)
{
	int	width;
	int	height;

	parser->indln = 0;
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	free(path);
	if (!(texture->img))
		return (ft_error("cub3D can't open texture", parser->line));
	texture->addr = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel),
			&(texture->line_length), &(texture->endian));
	if (!(texture->addr))
		return (ft_error("cub3D didn't find the memory to load", parser->line));
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
	double	cosi;
	double	sinu;

	cosi = cos(game->level.player.dir);
	sinu = sin(game->level.player.dir);
	mlx = game->mlx;
	mlx_screen = game->screen.mlx_screen;
	img = game->screen.pic_scrn.img;
	cub_render_walls(game);
	if (game->level.area.nb_sprite)
		cub_render_sprites(game);
	mlx_put_image_to_window(mlx, mlx_screen, img, 0, 0);
	if ((game->keys.z && !(game->keys.s)) || (!(game->keys.z) && game->keys.s))
		cub_player_front_move(game, cosi, sinu);
	if ((game->keys.q && !(game->keys.d)) || (!(game->keys.q) && game->keys.d))
		cub_player_lateral_move(game, sinu, cosi);
	if ((game->keys.a_l && !(game->keys.a_r)) || (!(game->keys.a_l)
			&& game->keys.a_r))
		cub_player_rotate_move(game);
	if (game->keys.z || game->keys.s || game->keys.q || game->keys.d)
		cub_set_distance_sprite(&(game->level));
	return (TRUE);
}

void	cub_set_mlx_screen(t_game *game)
{
	t_screen		*screen;
	t_img_data		*pic_screen;
	t_resolution	resolution;

	screen = &(game->screen);
	pic_screen = &(screen->pic_scrn);
	resolution = game->screen.resolution;
	if (!(game->save))
		screen->mlx_screen = mlx_new_window(game->mlx,
				resolution.width, resolution.height, "cub3D");
	pic_screen->img = mlx_new_image(game->mlx,
			resolution.width, resolution.height);
	pic_screen->addr = mlx_get_data_addr(
			screen->pic_scrn.img, &(pic_screen->bits_per_pixel),
			&(pic_screen->line_length), &(pic_screen->endian));
}
