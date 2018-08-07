/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:22:31 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 22:06:50 by eaptekar         ###   ########.fr       */
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
# include "libft.h"

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
# define K_SPMINUS 	33
# define K_SPPLUS 	30

# define WHITE		0x00FFFFFF
# define RED		0x00FE0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define CYAN		0x0000FFFF
# define YELLOW		0x00FFFF00
# define PURPLE		0x00FF00FF
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
	long int		colour;
}					t_point;

typedef	struct		s_map
{
	size_t			height;
	size_t			width;
	size_t			p_amount;
	int				scr_w;
	int				scr_h;
	int				speed;
	int				alpha;
	int				beta;
	int				gamma;
	t_point			*points;
	t_point			center;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_map;

int					key_hook(int	keycode, t_map *map);
void				render(t_map *map);
void				centring(t_map *map);
void				scaling(t_map *map, double scale);
void				moving_center(t_map *map);
void				shifting(t_map *map, int shift_x, int shift_y);
void				making_pixel(t_point *pixel, char *str, int row, int colum);
void				rotating(t_map *map, int axis, int angle);
int					map_open(int argc, char **argv);
t_map				map_create(int fd);
size_t				parse_line(char *line, t_list **list, size_t j);
void				draw_frame(t_map *map);
int					exit_x(void *param);
void				key_change_angle(int kcode, t_map *map);

#endif
