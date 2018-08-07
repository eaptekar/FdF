/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 19:39:42 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 21:25:16 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centring(t_map *map)
{
	map->center.x = (map->points[map->p_amount - 1].x +
		map->points[0].x) / 2;
	map->center.y = (map->points[map->p_amount - 1].y +
		map->points[0].y) / 2;
}

void	moving_center(t_map *map)
{
	t_var	tmp;

	tmp.y = (map->scr_h) / 2 - map->center.y;
	tmp.x = (map->scr_w) / 2 - map->center.x;
	shifting(map, tmp.x, tmp.y);
}

void	shifting(t_map *map, int shift_x, int shift_y)
{
	size_t	i;

	i = 0;
	while (i < map->p_amount)
	{
		map->points[i].x = map->points[i].x + shift_x;
		map->points[i].y = map->points[i].y + shift_y;
		i++;
	}
}

void	scaling(t_map *map, double scale)
{
	size_t	i;

	i = 0;
	while (i < map->p_amount)
	{
		map->points[i].x = (map->points[i].x - map->center.x) * scale + \
		map->center.x;
		map->points[i].y = (map->points[i].y - map->center.y) * scale + \
		map->center.y;
		map->points[i].z = map->points[i].z * scale;
		i++;
	}
}
