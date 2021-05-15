/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original_cub_renders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/15 14:45:47 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_dda_hrztl(t_game *game, t_walls *walls, double ray_angle)
{
	if (ray_angle == M_PI || ray_angle == 0)
		return (FALSE);
	if (ray_angle < M_PI && ray_angle > 0)
	{	
		//walls->offset_x = ;
		//walls->offset_y = SIDE;
		walls->h_wall_y = (int)(game->level.player.pos_y / SIDE) * SIDE - 1;
	}
	else
		walls->h_wall_y = (int)(game->level.player.pos_y / SIDE) * SIDE + 64;
	walls->h_wall_x = game->level.player.pos_x  + (game->level.player.pos_y - walls->h_wall_y) / tan();
}

int	cub_dda_vhrtcl(t_game *game, t_walls *walls, double ray_angle)
{
	if (ray_angle == M_PI_2 || ray_angle == 3 * M_PI_2);
		return (FALSE);
	// rayon vers west
	if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
	{
		
		walls->offset_x = -SIDE;
		walls->offset_y = tan(ray_angle) * game->level.player.pos_y;
	}
	// rayon vers east
	else
		return (0);
}

void	cub_ceiling_floor(t_game *game, int x, int y, t_bool cf)
{
	if (cf)
		cub_set_my_mlx_pixel(game->screen.pic_screen, x, y,
			game->level.ceiling.color.argb);
	else
		cub_set_my_mlx_pixel(game->screen.pic_screen, x, y,
			game->level.floor.color.argb);
}

void	cub_map_render(t_game *game)
{
	int	pix_y;
	int pix_x;
	int	map_y;
	int	map_x;
	int color;
	
	map_y = -1;
	while (game->level.area.map[++map_y])
	{
		map_x = -1;
		while (game->level.area.map[map_y][++map_x])
		{
			if (game->level.area.map[map_y][map_x] == '1')
				color = 0xFFFFFF;
			else if (game->level.area.map[map_y][map_x] == '0')
				color = 0xDDDDDD;
			else
				color = 0xFBFBFB;
			pix_y = -1;
			while (++pix_y < 16)
			{
				pix_x = -1;
				while (++pix_x < 16)
				{
					if (game->level.area.map[map_y][map_x] != ' ')
						cub_set_my_mlx_pixel(game->screen.pic_screen,
							(map_x * 16) + pix_x, (map_y * 16) + pix_y, color);
				}
			}
		}
	}
}

void	cub_render(t_game *game)
{
	int		pix_y;
	int		pix_x;
	t_walls	walls;
	int		midl_height;
	double	ray_angle;

	midl_height = game->screen.resolution.height / 2;
	ray_angle = (game->level.player.dir - ((FOV / 2) * (M_PI / 180)));
	pix_x = -1;
	while (++pix_x < game->screen.resolution.width)
	{
		if (ray_angle > (M_PI * 2))
			ray_angle = ray_angle - (M_PI * 2);
		else if (ray_angle < 0)
			ray_angle = (M_PI * 2) - ray_angle;
		pix_y = -1;
		cub_dda_hrztl(game, &walls, ray_angle);
		cub_dda_vrtcl();
//		while (++pix_y < game->screen.resolution.width)
//		{
//			pix_x++;
//		}
		ray_angle += (FOV * (M_PI / 180)) / game->screen.resolution.width;
	}
//	pix_y = -1;
//	while (++pix_y < game->screen.resolution.height)
//	{
//		pix_x = -1;
//		while (++pix_x < game->screen.resolution.width)
//		{
//			if (pix_y < midl_height)
//				cub_ceiling_floor(game, pix_x, pix_y, TRUE);
//			else
//				cub_ceiling_floor(game, pix_x, pix_y, FALSE);
//		}
//	}
	cub_map_render(game);
}