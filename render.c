/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:44:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/01 20:36:22 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS
//CHECK ALL NULL RETURNS	

void	iso_projection(t_map *map)
{
	t_point		p;
	size_t		i;

	map->points_2d = ft_memalloc(map->p_amount * sizeof(t_point2d));
	i = 0;
	while (i < map->p_amount)
	{
		p = map->points[i];
		p.x -= map->center.x;
		p.y -= map->center.y;
		map->points_2d[i].x = p.x * cos(BETA) - p.y * sin(BETA);
		map->points_2d[i].y = p.x * sin(ALPHA) * sin(BETA) - \
		p.z * cos(ALPHA) + p.y * sin(ALPHA) * cos(BETA);
		map->points_2d[i].x += map->center.x;
		map->points_2d[i].y += map->center.y;
		map->points_2d[i].colour = p.colour;
		i++;
	}
}

void	rotate_x(t_map *map, double ang)
{
	t_point		p;
	size_t		i;

	i = 0;
	while (i < map->p_amount)
	{
		p = map->points[i];
		p.x -= map->center.x;
		p.y -= map->center.y;
		map->points[i].x = p.x + map->center.x;
		map->points[i].y = p.y * cos(ang) - p.z * sin(ang) + map->center.y;
		map->points[i].z = p.y * sin(ang) + p.z * cos(ang);
		i++;
	}
}

void	rotate_y(t_map *map, double ang)
{
	t_point		p;
	size_t		i;

	i = 0;
	while (i < map->p_amount)
	{
		p = map->points[i];
		p.x -= map->center.x;
		p.y -= map->center.y;
		map->points[i].x = p.x * cos(ang) + p.z * sin(ang) + map->center.x;
		map->points[i].y = p.y + map->center.y;
		map->points[i].z = -p.x * sin(ang) + p.z * cos(ang);
		i++;
	}
}

void	rotate_z(t_map *map, double ang)
{
	t_point		p;
	size_t		i;

	i = 0;
	while (i < map->p_amount)
	{
		p = map->points[i];
		p.x -= map->center.x;
		p.y -= map->center.y;
		map->points[i].x = p.x * cos(ang) - p.y * sin(ang) + map->center.x;
		map->points[i].y = p.x * sin(ang) + p.y * cos(ang) + map->center.y;
		map->points[i].z = p.z;
		map->points[i].colour = p.colour;
		i++;
	}
}

void	orthogonal(t_map *map)
{
	t_point		p;
	size_t		i;

	map->points_2d = ft_memalloc(map->p_amount * sizeof(t_point2d));
	i = 0;
	while (i < map->p_amount)
	{
		p = map->points[i];
		map->points_2d[i].x = p.x;
		map->points_2d[i].y = p.y;
		map->points_2d[i].colour = p.colour;
		i++;
	}
}

void	centring(t_map *map)
{
	t_point2d	tmp;
	size_t		i;

	i = 0;
	map->center.x = (map->points[0].x + map->points[map->p_amount - 1].x) / 2;
	map->center.y = (map->points[0].y + map->points[map->p_amount - 1].y) / 2;
	tmp.x = (map->scr_w / 2) - map->center.x;
	tmp.y = (map->scr_h / 2) - map->center.y;
	while (i < map->p_amount)
	{
		map->points[i].x += tmp.x;
		map->points[i].y += tmp.y;
		i++;
	}
}

void	render(t_map *map)
{
	scr_size(map);
	centring(map);
	iso_projection(map);
//	orthogonal(map);
}
