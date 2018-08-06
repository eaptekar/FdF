/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:35:19 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 20:59:42 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	getting_pic(t_map *map)
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
			if (w < map->width - 1)
				drawing_line(map, &map->points[i], &map->points[i + 1]);
			if (h < map->height - 1)
				drawing_line(map, &map->points[i], &map->points[i + map->width]);
			w++;
			i++;
		}
		h++;
	}
	info(map);
}

void	drawing_line(t_map *map, t_point *p0, t_point *p1)
{
	double x;
	double y;

	x = p0->x;
	y = p0->y;
	if (fabs(p1->y - p0->y) > fabs(p1->x - p0->x))
	{
		while (p0->y > p1->y ? y >= p1->y : y <= p1->y)
		{
			x = ((y - p0->y) / (p1->y - p0->y) * (p1->x - p0->x) + p0->x);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0->color);
			p1->y > p0->y ? y++ : y--;
		}
	}
	else
	{
		while (p0->x > p1->x ? x >= p1->x : x <= p1->x)
		{
			y = ((x - p0->x) / (p1->x - p0->x) * (p1->y - p0->y) + p0->y);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0->color);
			p1->x > p0->x ? x++ : x--;
		}
	}
}
