/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:22:31 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 20:50:20 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

# define PI 		3.14159265359
# define HEIGHT		1200
# define WIDTH 		1200
# define K_LEFT		123
# define K_RIGHT	124
# define K_DOWN		125
# define K_UP		126
# define K_ESC		53
# define K_PLUS		69
# define K_MINUS	78
# define K_W 		13
# define K_S 		1
# define K_A		0
# define K_D 		2
# define K_Q 		12
# define K_E 		14
# define K_RED 		15
# define K_GREEN 	5
# define K_BLUE 	11
# define K_PURPLE 	35
# define K_YELLOW 	16

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define CYAN		0x00FFFF
# define YELLOW		0xFFFF00
# define PURPLE		0xFF00FF
# define DEFAULT	WHITE

# define ERROR(X)		ft_putendl_exit(X, -1)

typedef struct		s_var
{
	size_t			x;
	size_t			y;
}					t_var;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	long int		color;
}					t_point;

typedef	struct		s_map
{
	size_t			height;
	size_t			width;
	size_t			p_amount;
	t_point			*points;
	t_point			*centre;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
}					t_map;

// char				**reading_map(char *av);
// size_t				counting_strs(char *av);
// size_t				counting_rows(char **av);
// size_t				counting_colums(char *str);
int					validating_mapsize(char **ret_map);
int					key_hook(int	keycode, t_map *map);
void				key_redcolor(t_map *map);
void				key_greencolor(t_map *map);
void				key_bluecolor(t_map *map);
void				key_purplecolor(t_map *map);
void				key_yellowcolor(t_map *map);
// void				next_step(char **av);
void				key_moving(int	kcode, t_map *map);
void				key_scale(int kcode, t_map *map);
void				drawing_line(t_map *map, t_point *p0, t_point *p1);
void				getting_pic(t_map *map);
void				centring(t_map *map);
void				scaling(t_map *map, double scale);
void				moving_centre(t_map *map);
void				moving_y(t_map *map, int down);
void				moving_x(t_map *map, int right);
// void				validating_map(char **ret_map);
void				making_pixel(t_point *pixel, char *str, int row, int colum);
void				info(t_map *map);
// void				free_pixel(char **str);
void				rotating(t_map *map, int kcode);
t_point				rotating_x(t_point *pixel, t_point *centre, int ang);
t_point				rotating_y(t_point *pixel, t_point *centre, int ang);
t_point				rotating_z(t_point *pixel, t_point *centre, int ang);
// t_map				*creating_map(char	**ret_map, size_t rows, size_t colums);
// t_map				*list_map(size_t rows, size_t colums);
// t_map				*creating_map(char	**ret_map, size_t rows, size_t colums);
int					map_open(int argc, char **argv);
t_map				map_create(int fd);
size_t				parse_line(char *line, t_list **list, size_t j);

#endif
