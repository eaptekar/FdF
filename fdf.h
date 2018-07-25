/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:41:46 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/25 18:55:01 by eaptekar         ###   ########.fr       */
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
# include "libft/libft.h"

# define ESC 53
# define WHITE 0xFFFFFF
# define DEFAULT 0xFFFFFF

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			tx;
	int			ty;
}				t_point;

typedef struct	s_map
{
	size_t		width;
	size_t		height;
	size_t		p_amount;
	t_point		*point;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_map;

void	draw_map(void);
t_map	map_create(int fd);
size_t	parse_line(char *line, t_list **list);

#endif
