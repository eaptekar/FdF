/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 19:45:44 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 21:28:28 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		str_line(t_map *map, t_point a, t_point b)
{
	if (a.x == b.x)
	{
		while (a.y != b.y)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
			(a.y < b.y) ? a.y++ : a.y--;
		}
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
	}
	else
	{
		while (a.x != b.x)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
			(a.x < b.x) ? a.x++ : a.x--;
		}
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
	}
}

static t_point	make_t2(int x, int y)
{
	t_point	a;

	a.x = x;
	a.y = y;
	a.colour = WHITE;
	return (a);
}

void			draw_frame(t_map *map)
{
	str_line(map, make_t2(10, 10), make_t2(10, map->scr_h - 10));
	str_line(map, make_t2(map->scr_w - 10, 10), \
		make_t2(map->scr_w - 10, map->scr_h - 10));
	str_line(map, make_t2(10, 10), make_t2(map->scr_w - 10, 10));
	str_line(map, make_t2(10, map->scr_h - 10), \
		make_t2(map->scr_w - 10, map->scr_h - 10));
}
