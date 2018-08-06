/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:57:16 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 20:41:53 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		rotating_y(t_point *pixel, t_point *centre, int ang)
{
	t_point	tmp;
	double	angle;

	pixel->x = pixel->x - centre->x;
	pixel->y = pixel->y - centre->y;
	angle = ang * PI / 180;
	tmp.x = pixel->x;
	tmp.y = pixel->y * cos(angle) + pixel->z * sin(angle);
	tmp.z = (-(pixel->y) * sin(angle)) + pixel->z * cos(angle);
	tmp.color = pixel->color;
	tmp.x = tmp.x + centre->x;
	tmp.y = tmp.y + centre->y;
	return (tmp);
}

t_point		rotating_x(t_point *pixel, t_point *centre, int ang)
{
	t_point	tmp;
	double	angle;

	pixel->x = pixel->x - centre->x;
	pixel->y = pixel->y - centre->y;
	angle = ang * PI / 180;
	tmp.x = pixel->x * cos(angle) + pixel->z * sin(angle);
	tmp.y = pixel->y;
	tmp.z = -(pixel->x) * sin(angle) + pixel->z * cos(angle);
	tmp.color = pixel->color;
	tmp.x = tmp.x + centre->x;
	tmp.y = tmp.y + centre->y;
	return (tmp);
}

t_point		rotating_z(t_point *pixel, t_point *centre, int ang)
{
	t_point	tmp;
	double	angle;

	pixel->x = pixel->x - centre->x;
	pixel->y = pixel->y - centre->y;
	angle = ang * PI / 180;
	tmp.x = pixel->x * cos(angle) - pixel->y * sin(angle);
	tmp.y = pixel->x * sin(angle) + pixel->y * cos(angle);
	tmp.z = pixel->z;
	tmp.color = pixel->color;
	tmp.x = tmp.x + centre->x;
	tmp.y = tmp.y + centre->y;
	return (tmp);
}

void		rotating(t_map *map, int kcode)
{
	size_t	i;

	i = 0;
	while (i < map->p_amount)
	{
		if (kcode == K_A)
			map->points[i] = rotating_x(&map->points[i], map->centre, -10);
		else if (kcode == K_D)
			map->points[i] = rotating_x(&map->points[i], map->centre, 10);
		else if (kcode == K_W)
			map->points[i] = rotating_y(&map->points[i], map->centre, -10);
		else if (kcode == K_S)
			map->points[i] = rotating_y(&map->points[i], map->centre, 10);
		else if (kcode == K_Q)
			map->points[i] = rotating_z(&map->points[i], map->centre, 10);
		else if (kcode == K_E)
			map->points[i] = rotating_z(&map->points[i], map->centre, -10);
		i++;
	}
}
