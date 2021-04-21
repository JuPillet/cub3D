/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:31:11 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 23:19:34 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cubRT_H
# define cubRT_H
# define BUFFER_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "mlx.h"
# include "../libft/libft.h"
# include "libft.h"

typedef struct	s_color
{
	int *a;
	int *r;
	int *g;
	int *b;
	int	*argb;
}				t_color;

typedef struct  s_img_data
{
	void		*img;
	char		*addr;
	int			*bits_per_pixel;
	int			*line_length;
	int			*endian;
}				t_img_data;

typedef	struct	s_texture
{
	t_bool	*is;
	char	*path;
}				t_texture;

typedef struct	s_horizon
{
	t_bool	*is;
	t_color	*color;
}				t_horizon;

typedef struct	s_player
{
	t_bool		*is;
	double		*position_x;
	double		*position_y;
	double		*orientation;
}				t_player;

typedef struct	s_level
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	t_texture	*sp;
	t_horizon	*flour;
	t_horizon	*ceiling;
	t_player	*player;
	char		**map;
}				t_level;

typedef struct	s_resolution
{
	t_bool		*is;
	int			*width;
	int			*height;
	int			*pixel_x;
	int			*pixel_y;
	double		*fov;
}				t_resolution;

typedef	struct	s_screen
{
	t_resolution	*resolution;
	void			*mlx;
	void			*mlx_screen;
	t_img_data		*pic_screen;
}				t_screen;

typedef struct	s_game	t_game;
typedef t_bool (*t_pt_fnct)(char *line, int *indln, t_game *game);
typedef struct	s_hash_array
{
	char		*keylen;
	char		*key;
	t_pt_fnct	*pt_fonction;
}				t_hash_array;

struct	s_game
{
	t_hash_array	*hash_array;
	t_screen		*screen;
	t_level			*level;
};

typedef struct	s_parser
{
	int				fd;
	int				fd_map;
	char			*line;
	int				eof;
}				t_parser;

t_bool			cub_set_int(char *line, int *indln, int *value);
t_bool			cub_set_double(char *line, int *indln, double *value);

int				get_a(int argb);
int				get_r(int argb);
int				get_g(int argb);
int				get_b(int argb);
void			cub_set_my_mlx_pixel(t_img_data *data, int x, int y, int color);
int				cub_set_shade(double distance, int color);
int				cub_set_opposite(int trgb);
int				cub_set_argb(int a, int r, int g, int b);

t_bool			cub_parse_resolution(char *line, int *indln, t_game *game);

t_bool			cub_free_player(t_player **player);
t_bool			cub_malloc_player(t_player **player);

t_bool			cub_free_screen(t_screen **screen);
t_bool			cub_malloc_screen(t_screen **screen);

t_bool			cub_free_functions_pointer(t_pt_fnct **pt_function);
t_bool			cub_free_fonctions_hash_array(t_hash_array **hash_array);
void		 	cub_set_key_hash_array(t_hash_array *array);
void			cub_set_keylen_hash_array(t_hash_array *array);
void			cub_set_pt_fonctions_hash_array(t_hash_array *array);
t_bool			cub_malloc_functions_pointer(t_pt_fnct **pt_function);
void			cub_malloc_fonctions_hash_array_zero_init(t_hash_array **hash_array);
t_bool			cub_malloc_fonctions_hash_array(t_hash_array **array);

t_bool			cub_norm_file(const char *file, t_game *pov);
t_bool			cub_parser(const char *file, t_game *pov);


t_bool			cub_render(t_game *pov);

int				main(int ac, char **av);

#endif