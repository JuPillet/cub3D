/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:49:17 by jpillet           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/16 19:13:39 by jpillet          ###   ########.fr       */
=======
/*   Updated: 2021/06/10 21:32:18 by jpillet          ###   ########.fr       */
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

<<<<<<< HEAD
void	cub_print_sprite(t_game *game, t_sprite *sprt, int start)
{
	int		pix_y;
=======
void	cub_invisibilize_sprite(t_area *area)
{
	int	crnt_sprite;

	crnt_sprite = -1;
	while (++crnt_sprite < area->nb_sprite)
		area->sprite[crnt_sprite].visible = FALSE;
}

void	cub_print_sprite(t_game *game, t_sprite *sprt, int start)
{
	int		pix_y;
	int		stop;
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
	int		argb;
	double	sprt_y;

	if (start < 0)
		start = 0;
	start -= 1;
<<<<<<< HEAD
	while (++start < game->screen.resolution.width && sprt->sprite_x <= (SIDE - 1))
	{
		if (sprt->distance < game->level.area.dist_walls[start])
		{
			pix_y = sprt->top;
			sprt_y = sprt->sprite_y;
			if (pix_y < 0)
				pix_y = 0;
			pix_y -= 1;
			while (++pix_y < game->screen.resolution.height && sprt_y < SIDE)
			{
				argb = cub_get_texture_sprite(game->level.sp.addr, sprt, sprt_y);
				if (argb)
					cub_set_my_mlx_pixel(game->screen.pic_scrn, start, pix_y, argb);
				sprt_y += sprt->pix_o_s;
			}
=======
	while (++start < game->screen.resolution.width && (int)(sprt->sprite_x) < SIDE)
	{
		pix_y = sprt->top;
		sprt_y = sprt->sprite_y;
		if (pix_y < 0)
			pix_y = 0;
		pix_y -= 1;
		while ((++pix_y) < sprt->end && pix_y < game->screen.resolution.height)
		{
			argb = cub_get_texture_sprite(game->level.sp.addr, sprt, sprt_y);
			if (argb)
				cub_set_my_mlx_pixel(game->screen.pic_scrn, start, pix_y, argb);
			sprt_y += sprt->pix_o_s;
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
		}
		sprt->sprite_x += sprt->pix_o_s;
	}
}

void	cub_init_print_sprite(t_game *game, t_sprite *sprt, int *start)
{
	sprt->height = (SIDE / sprt->distance)
		* game->screen.resolution.dist_plan;
<<<<<<< HEAD
	sprt->top = game->screen.resolution.height_mdl - (sprt->height / 2);
	sprt->r_x_sprite = atan2((game->level.player.pos_y - sprt->pos_y),
			(sprt->pos_x - game->level.player.pos_x));
=======
	sprt->demi_height = (sprt->height / 2);
	sprt->top = game->screen.resolution.height_mdl - (sprt->demi_height);
	sprt->end = game->screen.resolution.height - sprt->top;
	printf("\n%d\n", sprt->top);
	printf("\n%d\n", sprt->end);
	sprt->r_x_sprite = atan2((game->level.player.pos_y - sprt->pos_y),
		(sprt->pos_x - game->level.player.pos_x));
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
	sprt->r_x_sprite = game->level.player.dir - sprt->r_x_sprite
		+ game->screen.resolution.r_demi_fov;
	if (sprt->r_x_sprite > game->deg.r360)
		sprt->r_x_sprite -= game->deg.r360;
	else if (sprt->r_x_sprite < 0)
		sprt->r_x_sprite += game->deg.r360;
<<<<<<< HEAD
	(*start) = (int)((sprt->r_x_sprite / game->screen.resolution.r_o_s_pix)
			- sprt->height / 2);
	sprt->pix_o_s = ((double)(SIDE) / sprt->height);
=======
	(*start) = (int)(sprt->r_x_sprite / game->screen.resolution.r_o_s_pix);
	(*start) -= sprt->demi_height;
	sprt->pix_o_s = (SIDE / sprt->height);
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
	sprt->sprite_x = 0;
	if (*start < 0)
		sprt->sprite_x = -((*start) * sprt->pix_o_s);
	sprt->sprite_y = 0;
	if (sprt->top < 0)
		sprt->sprite_y = -(sprt->top * sprt->pix_o_s);
}

void	cub_render_sprites(t_game *game)
{
<<<<<<< HEAD
	int			crnt_sprite;
	int			start;
	t_sprite	*sprt;

	sprt = game->level.area.sprite;
	crnt_sprite = -1;
=======
	int	crnt_sprite;
	int	start;
	t_sprite *sprt;
	
	sprt = game->level.area.sprite;
	crnt_sprite = -1;
	system("clear");
	printf("\n%f\n", game->level.player.pos_x);
	printf("\n%f\n\n", game->level.player.pos_y);
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
	while (++crnt_sprite < game->level.area.nb_sprite)
	{
		if (sprt[crnt_sprite].visible)
		{
			cub_init_print_sprite(game, &(sprt[crnt_sprite]), &start);
			cub_print_sprite(game, &(sprt[crnt_sprite]), start);
<<<<<<< HEAD
			sprt[crnt_sprite].visible = FALSE;
		}
	}
}
=======
		}
	}
}
>>>>>>> 218e8b58bde0b57e17c7b75c0c3d1f0537dea2eb
