/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:21:38 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/01 17:45:50 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS
//CHECK ALL NULL RETURNS

/*static void	bresenham_line(t_map *map, t_point2d a, t_point2d b)
{
	int		err;
	int		y;
	int		x;

	err = 0;
	y = a.y;
	x = a.x;
	while (x != b.x)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, a.colour);
		err += ft_abs(b.y - a.y);
		if ((err * 2) >= ft_abs(b.x - a.x))
		{
			y += ((b.y - a.y) > 0 ? 1 : -1);
			err -= ft_abs(b.x - a.x);
		}
		b.x > a.x ? x++ : x--;
	}
	while (y != b.y && a.x == b.x)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, a.colour);
		b.y > a.y ? y++ : y--;
	}
}*/

static void	bresenham_line(t_map *map, t_point2d p0, t_point2d p1)
{
	double x;
	double y;

	x = p0.x;
	y = p0.y;
	if (ft_abs(p1.y - p0.y) > ft_abs(p1.x - p0.x))
	{
		while (p0.y > p1.y ? y >= p1.y : y <= p1.y)
		{
			x = ((y - p0.y) / (p1.y - p0.y) * (p1.x - p0.x) + p0.x);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0.colour);
			p1.y > p0.y ? y++ : y--;
		}
	}
	else
	{
		while (p0.x > p1.x ? x >= p1.x : x <= p1.x)
		{
			y = ((x - p0.x) / (p1.x - p0.x) * (p1.y - p0.y) + p0.y);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0.colour);
			p1.x > p0.x ? x++ : x--;
		}
	}
}

static void	draw_lines(t_map *map)
{
	size_t	i;
	size_t	w;
	size_t	h;

	i = 0;
	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (w + 1 < map->width)
				bresenham_line(map, map->points_2d[i], map->points_2d[i + 1]);
			if (h + 1 < map->height)
				bresenham_line(map, map->points_2d[i], \
					map->points_2d[i + map->width]);
			w++;
			i++;
		}
		h++;
	}
}

t_point2d	make_t2(int x, int y)
{
	t_point2d a;

	a.x = x;
	a.y = y;
	a.colour = WHITE;
	return (a);
}

static void	put_legend(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 11, 0x80AAFF,
		"Rotate X = A or D");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 31, 0xAA80FF,
		"Rotate Y = W or S");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 51, 0x80FFAA,
		"Rotate Z = Q or E");
	mlx_string_put(map->mlx_ptr, map->win_ptr, map->scr_w - 151, 11, 0xFFAA80,
		"Exit = Esc");
}

void		draw_map(t_map *map)
{
	bresenham_line(map, make_t2(10, 10), make_t2(10, map->scr_h - 10));
	bresenham_line(map, make_t2(map->scr_w - 10, 10), \
		make_t2(map->scr_w - 10, map->scr_h - 10));
	bresenham_line(map, make_t2(10, 10), make_t2(map->scr_w - 10, 10));
	bresenham_line(map, make_t2(10, map->scr_h - 10), \
		make_t2(map->scr_w - 10, map->scr_h - 10));
	draw_lines(map);
	put_legend(map);
}
