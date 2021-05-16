/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:31:11 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/16 22:42:01 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 32
# define SIDE 64
# define FOV 60

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
	int a;
	int r;
	int g;
	int b;
	int	argb;
}				t_color;

typedef struct	s_walls
{
	double	r_agl;
	double	t_agl;
	double	c_agl;
	double	h_wall_x;
	double	h_wall_y;
	double	v_wall_x;
	double	v_wall_y;
	double	check_x;
	double	check_y;
	t_bool	h_wall;
	t_bool	v_wall;
}				t_walls;

typedef struct  s_img_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct	s_horizon
{
	t_bool	is;
	t_color	color;
}				t_horizon;

typedef struct	s_player
{
	t_bool		is;
	double		pos_x;
	double		pos_y;
	double		dir;
}				t_player;

typedef struct	s_area
{
	char 	**map;
	int		*lines_length;
	int		map_height;
}				t_area;

typedef struct	s_level
{
	void		*no;
	void		*so;
	void		*we;
	void		*ea;
	void		*sp;
	t_horizon	floor;
	t_horizon	ceiling;
	t_player	player;
	t_area		area;
}				t_level;

typedef struct	s_resolution
{
	t_bool		is;
	int			width;
	int			height;
	int			width_mdl;
	int			height_mdl;
	double		r_o_s;
	double		plan_dist;
	double		pi_2;
	double		cos_demi_fov;
}				t_resolution;

typedef	struct	s_screen
{
	t_resolution	resolution;
	void			*mlx_screen;
	t_img_data		pic_screen;
}				t_screen;

typedef struct	s_parser
{
	int				fd;
	char			*line;
	int				indln;
	int				eof;
}				t_parser;

typedef struct	s_game	t_game;
typedef t_bool (*t_pt_fnct)(t_parser *parser, t_game *game);
typedef struct	s_hash_array
{
	char		keylen;
	char		*key;
	t_pt_fnct	pt_fonction;
}				t_hash_array;

struct	s_game
{
	t_hash_array	*hash_array;
	t_parser		parser;
	void			*mlx;
	t_screen		screen;
	t_level			level;
	t_bool			save;
};

t_bool			cub_free_area(t_area area);
t_bool			cub_free_parser(t_parser *parser);
t_bool			cub_free_sprite(void *mlx, void *img);
t_bool			cub_free_screen(void *mlx, void *screen);
t_bool			cub_free_hash_array(t_game *game);
t_bool			cub_free_game(t_game *game);

t_bool			cub_set_int(char *line, int *indln, int *value);
t_bool			cub_set_double(char *line, int *indln, double *value);

int				get_a(int argb);
int				get_r(int argb);
int				get_g(int argb);
int				get_b(int argb);
void			cub_set_my_mlx_pixel(t_img_data data, int x, int y, int color);
int				cub_set_shade(double distance, int color);
int				cub_set_opposite(int trgb);
int				cub_set_argb(int a, int r, int g, int b);

int				cub_player_front_move(int key_code, t_game *game);
int				cub_player_lateral_move(int key_code, t_game *game);
int				cub_player_rotate_move(int key_code, t_game *game);
int				cub_key_push(int key_code, t_game *game);
t_bool			cub_coin(t_game *game);

t_bool			cub_set_mlx(void **mlx);
t_bool			cub_set_resolution(char *line, void *mlx, t_resolution *resolution);
void			cub_set_map_columns(char *line, char **line_map);

t_bool			cub_set_texture(t_game *game, t_parser *parser, char *path, void **texture);

void			cub_render_closest_wall(t_game *game, t_walls walls, double pix_x);

t_bool			cub_dda_check_map(t_area *area, int map_y, int map_x);
t_bool			cub_dda_check_vrtcl_wall(t_area *area, t_walls *walls, int map_y, int map_x);
t_bool			cub_dda_check_hrztl_wall(t_area *area, t_walls *walls, int map_y, int map_x);
t_bool			cub_dda_hrztl(t_level *lvl, t_walls *walls);
t_bool			cub_dda_vrtcl(t_level *lvl, t_walls *walls);

void			cub_ceiling_floor(t_game *game, int x, int y, t_bool cf);
void			cub_render_map(t_game *game);
void			cub_render_dda(t_game *game, t_walls *walls);
void			cub_render(t_game *game);

int				cub_set_image_to_window(t_game *game);
t_bool			cub_set_parser(const char *file, t_parser *parser);
t_bool			cub_set_int(char *line, int *indln, int *value);
t_bool			cub_set_double(char *line, int *indln, double *value);
void			cub_set_mlx_screen(t_game *game);

t_bool			cub_set_player(int map_x, int map_y, char **map, t_player *player);
t_bool			cub_search_player(char **map, t_player *player);

t_bool			cub_check_out_map(t_area area, int y, int x);
t_bool			cub_check_wall_map(t_area area, int y, int x);
t_bool			cub_check_in_map(t_level level, int y, int x);
t_bool			cub_check_map(t_level *level);

t_bool			cub_check_after_map(t_parser *parser, const char *file);
t_bool			cub_check_end_map(char *line);
t_bool			cub_get_map_line(t_parser *parser, char **line, const char *file);
t_bool			cub_loop_map(t_parser *parser, t_bool *loop, char **line);

void			cub_set_map_columns(char *line, char **line_map);
t_bool			cub_check_before_map(t_game *game);
t_bool			cub_check_start_map(char *line, int indln);

t_bool			cub_get_setting_line(t_parser *parser, const char *file);

t_bool			cub_malloc_map_columns(char *line, char **line_map, int *columns);
t_bool			cub_malloc_map_lines(t_game *game, char **line, int malloc_lines);
t_bool			cub_malloc_area(t_area **area);

t_bool			cub_parse_map(t_parser *parser, t_game *game, const char *file, int lines);

t_bool			cub_dispacher_fnct(int indpf, t_parser *parser, t_game *game);
t_bool			cub_dispatcher(const char *file, t_parser *parser, t_game *game);
t_bool			cub_get_setting_line(t_parser *parser, const char *file);

t_bool			cub_parser(const char *file, t_game *game);
t_bool			cub_norm_file(const char *file, t_game *game);

t_bool			cub_set_resolution(char *line, void *mlx, t_resolution *resolution);
t_bool			cub_parse_color(t_parser *parser, t_color *color);
t_bool			cub_set_texture(t_game *game, t_parser *parser, char *path, void **texture);

t_bool			cub_parse_texture_north(t_parser *parser, t_game *game);
t_bool			cub_parse_texture_east(t_parser *parser, t_game *game);
t_bool			cub_parse_texture_south(t_parser *parser, t_game *game);
t_bool			cub_parse_texture_west(t_parser *parser, t_game *game);
t_bool			cub_parse_texture_sprite(t_parser *parser, t_game *game);
t_bool			cub_parse_resolution(t_parser *parser, t_game *game);
t_bool			cub_set_horizon(t_parser *parser, t_game *game);

t_bool			cub_dispacher_fnct(int indpf, t_parser *parser, t_game *game);
t_bool			cub_dispatcher(const char *file, t_parser *parser, t_game *game);
t_bool			cub_parser(const char *file, t_game *game);
t_bool			cub_norm_file(const char *file, t_game *game);

t_bool			cub_is_save(int ac, char **av, t_bool *save);

void			cub_init_hash_array(t_hash_array *hash_array);
t_bool			cub_malloc_hash_array(t_game *game);
t_bool			cub_init_color(t_color *color);
t_bool			cub_init_level(t_game *game);
t_bool			cub_init_game(t_game *game);

int				main(int ac, char **av);

#endif