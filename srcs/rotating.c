/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:57:16 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/08 17:34:06 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_point		rotating_x(t_point *px, t_point cntr, int ang)
{
	t_point	tmp;
	double	angle;

	px->x = px->x - cntr.x;
	px->y = px->y - cntr.y;
	angle = deg_to_rad(ang);
	tmp.x = px->x + cntr.x;
	tmp.y = px->y * cos(angle) + px->z * sin(angle) + cntr.y;
	tmp.z = (-(px->y) * sin(angle)) + px->z * cos(angle);
	tmp.colour = px->colour;
	return (tmp);
}

static t_point		rotating_y(t_point *px, t_point cntr, int ang)
{
	t_point	tmp;
	double	angle;

	px->x = px->x - cntr.x;
	px->y = px->y - cntr.y;
	angle = deg_to_rad(ang);
	tmp.x = px->x * cos(angle) + px->z * sin(angle) + cntr.x;
	tmp.y = px->y + cntr.y;
	tmp.z = -(px->x) * sin(angle) + px->z * cos(angle);
	tmp.colour = px->colour;
	return (tmp);
}

static t_point		rotating_z(t_point *px, t_point cntr, int ang)
{
	t_point	tmp;
	double	angle;

	px->x = px->x - cntr.x;
	px->y = px->y - cntr.y;
	angle = deg_to_rad(ang);
	tmp.x = px->x * cos(angle) - px->y * sin(angle) + cntr.x;
	tmp.y = px->x * sin(angle) + px->y * cos(angle) + cntr.y;
	tmp.z = px->z;
	tmp.colour = px->colour;
	return (tmp);
}

void				rotating(t_map *map, int axis, int angle)
{
	size_t	i;

	i = 0;
	while (i < map->p_amount)
	{
		if (axis == 1)
			map->points[i] = rotating_x(&map->points[i], map->center, angle);
		else if (axis == 2)
			map->points[i] = rotating_y(&map->points[i], map->center, angle);
		else if (axis == 3)
			map->points[i] = rotating_z(&map->points[i], map->center, angle);
		i++;
	}
}
