/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:41:46 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/01 20:06:26 by eaptekar         ###   ########.fr       */
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

# define ESC 		53

# define SCR_W_M	1280
# define SCR_H_M	960
# define SCR_W_L	2565
# define SCR_H_L	1400

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define CYAN		0x00FFFF
# define YELLOW		0xFFFF00
# define PURPLE		0xFF00FF
# define DEFAULT	WHITE

# define ALPHA		0.463646716
# define BETA		0.785398
# define GAMMA		0
# define ANGLE		5

# define ERROR(X)		ft_putendl_exit(X, -1)

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
}				t_point;

typedef struct	s_point2d
{
	int			x;
	int			y;
	int			colour;
}				t_point2d;

typedef struct	s_map
{
	size_t		width;
	size_t		height;
	size_t		p_amount;
	t_point		*points;
	t_point2d	*points_2d;
	t_point2d	center;
	int			scr_w;
	int			scr_h;
	int			z_size;
	double		ang_a;
	double		ang_b;
	double		ang_g;
	double		ang;  //for tests
	void		*mlx_ptr;
	void		*win_ptr;
}				t_map;

int				map_open(int argc, char **argv);
t_map			map_create(int fd);
size_t			parse_line(char *line, t_list **list, size_t j);
t_map			map_get_points(t_map map, t_list *list);

void			render(t_map *map);
void			rotate_x(t_map *map, double ang);
void			rotate_y(t_map *map, double ang);
void			rotate_z(t_map *map, double ang);

void			scr_size(t_map *map);

void			draw_map(t_map *map);

#endif
