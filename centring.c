/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:28:04 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 20:28:39 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centring(t_map *map)
{
	map->centre = (t_point *)malloc(sizeof(t_point));
	map->centre->x = (map->points[map->p_amount - 1].x +
		map->points[0].x) / 2;
	map->centre->y = (map->points[map->p_amount - 1].y +
		map->points[0].y) / 2;
}

void	moving_centre(t_map *map)
{
	t_var	tmp;

	tmp.y = (HEIGHT) / 2 - map->centre->y;
	tmp.x = (WIDTH) / 2 - map->centre->x;
	moving_y(map, tmp.y);
	moving_x(map, tmp.x);
}

void	moving_y(t_map *map, int down)
{
	size_t	i;

	i = 0;
	while(i < map->p_amount)
	{
		map->points[i].y = map->points[i].y + down;
		i++;	
	}
}

void	moving_x(t_map *map, int right)
{
	size_t	i;

	i = 0;
	while (i < map->p_amount)
	{
		map->points[i].x = map->points[i].x + right;
		i++;
	}
}

void	scaling(t_map *map, double scale)
{
	size_t	i;

	i = 0;
	while (i < map->p_amount)
	{
		map->points[i].x = (map->points[i].x - 
			map->centre->x) * scale + map->centre->x;
		map->points[i].y = (map->points[i].y - 
			map->centre->y) * scale + map->centre->y;
		map->points[i].z = map->points[i].z * scale;
		i++;
	}
}
