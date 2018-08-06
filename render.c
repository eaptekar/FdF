/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:44:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 15:42:16 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS BEFORE EXIT
//CHECK ALL NULL RETURNS

#include <stdio.h>


// void	iso_projection(t_map *map)
// {
// 	t_point		p;
// 	t_point		temp;
// 	size_t		i;

// 	i = 0;
// 	while (i < map->p_amount)
// 	{
// 		p = map->points[i];
// 		// p.x -= map->center.x;
// 		// p.y -= map->center.y;
// 		temp.x = p.x;
// 		temp.y = p.y * cos(deg_to_rad(30)) + p.z * sin(deg_to_rad(30));
// 		temp.z = -p.y * sin(deg_to_rad(30)) + p.z * cos(deg_to_rad(30));
// 		// temp.y = p.x * sin(ALPHA) * sin(BETA) - \
// 		// p.z * cos(ALPHA) + p.y * sin(ALPHA) * cos(BETA);
// 		map->points[i].x = temp.x;// + map->center.x;
// 		map->points[i].y = temp.y;// + map->center.y;
// 		map->points[i].z = temp.z;
// 		i++;
// 	}
// }

void	rotate(t_map *map, t_point *px)
{
	float	coord[2];
	double	angle;

	angle = deg_to_rad(map->alpha);
	coord[0] = px->y * cos(angle) - px->z * sin(angle);
	coord[1] = px->y * sin(angle) + px->z * cos(angle);
	px->y = round(coord[0]);
	px->z = round(coord[1]);
	angle = deg_to_rad(map->beta);
	coord[0] = px->x * cos(angle) + px->z * sin(angle);
	coord[1] = -px->x * sin(angle) + px->z * cos(angle);
	px->x = round(coord[0]);
	px->z = round(coord[1]);
	angle = deg_to_rad(map->gamma);
	coord[0] = px->x * cos(angle) + px->y * sin(angle);
	coord[1] = -px->x *sin(angle) + px->y * cos(angle);
	px->x = round(coord[0]);
	px->y = round(coord[1]); 
}

void	transform(t_map *map)
{
	size_t	i;
	t_point	temp;

	i = 0;
	while (i < map->p_amount)
	{
		temp.x = map->scale * (i % map->width - map->width / 2);
		temp.y = map->scale * (i % map->height - map->height / 2);
		temp.z = map->points[i].z * map->z_size;
		rotate(map, &temp);
		map->points[i].x = (temp.x / (temp.z - 1000)) * (250 - 1000);
		map->points[i].x += map->scr_w / 2;
		map->points[i].y = (temp.y / (temp.z - 1000)) * (250 - 1000);
		map->points[i].y += map->scr_h / 2;
		printf("[%zu] (%d, %d, %d) %X\n", i, map->points[i].x, map->points[i].y, map->points[i].z, map->points[i].colour);
		i++;
	}
}

// void	rotate_x(t_map *map, double ang)
// {
// 	t_point		p;
// 	t_point		temp;
// 	size_t		i;

// 	i = 0;
// 	while (i < map->p_amount)
// 	{
// 		p = map->points[i];
// 		// p.x -= map->center.x;
// 		// p.y -= map->center.y;
// 		temp.x = p.x;
// 		temp.y = p.y * cos(ang) - p.z * sin(ang);
// 		temp.z = p.y * sin(ang) + p.z * cos(ang);
// 		map->points[i].x = temp.x;// + map->center.x;
// 		map->points[i].y = temp.y;// + map->center.y;
// 		map->points[i].z = temp.z;
// 		i++;
// 	}
// }

// void	rotate_y(t_map *map, double ang)
// {
// 	t_point		p;
// 	t_point		temp;
// 	size_t		i;

// 	i = 0;
// 	while (i < map->p_amount)
// 	{
// 		p = map->points[i];
// 		// p.x -= map->center.x;
// 		// p.y -= map->center.y;
// 		temp.x = p.x * cos(ang) + p.z * sin(ang);
// 		temp.y = p.y;
// 		temp.z = -p.x * sin(ang) + p.z * cos(ang);
// 		map->points[i].x = temp.x;// + map->center.x;
// 		map->points[i].y = temp.y;// + map->center.y;
// 		map->points[i].z = temp.z;
// 		i++;
// 	}
// }

// void	rotate_z(t_map *map, double ang)
// {
// 	t_point		p;
// 	t_point		temp;
// 	size_t		i;

// 	i = 0;
// 	while (i < map->p_amount)
// 	{
// 		p = map->points[i];
// 		// p.x -= map->center.x;
// 		// p.y -= map->center.y;
// 		temp.x = p.x * cos(ang) - p.y * sin(ang);
// 		temp.y = p.x * sin(ang) + p.y * cos(ang);
// 		temp.z = p.z;
// 		map->points[i].x = temp.x;// + map->center.x;
// 		map->points[i].y = temp.y;// + map->center.y;
// 		map->points[i].z = temp.z;
// 		i++;
// 	}
// }

// void	orthogonal(t_map *map)
// {
// 	t_point		p;
// 	size_t		i;

// 	map->points_2d = ft_memalloc(map->p_amount * sizeof(t_point2d));
// 	i = 0;
// 	while (i < map->p_amount)
// 	{
// 		p = map->points[i];
// 		map->points_2d[i].x = p.x;
// 		map->points_2d[i].y = p.y;
// 		map->points_2d[i].colour = p.colour;
// 		i++;
// 	}
// }

// void	centring(t_map *map)
// {
// 	t_point2d	tmp;
// 	size_t		i;

// 	i = 0;
// 	map->center.x = (map->points[0].x + map->points[map->p_amount - 1].x) / 2;
// 	map->center.y = (map->points[0].y + map->points[map->p_amount - 1].y) / 2;
// 	tmp.x = (map->scr_w / 2) - map->center.x;
// 	tmp.y = (map->scr_h / 2) - map->center.y;
// 	while (i < map->p_amount)
// 	{
// 		map->points[i].x += tmp.x;
// 		map->points[i].y += tmp.y;
// 		i++;
// 	}
// }

void	render(t_map *map)
{
	// size_t		i;
	// t_point		p;

	// iso_projection(map);
//	centring(map);
	transform(map);

	// i = 0;
	// printf("---------------------\n____3D_COORDINATES_____\n");
	// while (i < map->p_amount)
	// {
	// 	p = map->points[i];
	// 	printf("[%zu] (%d, %d, %d) %X\n", i, p.x, p.y, p.z, p.colour);
	// 	i++;
	// }
	// printf("---------------------\n\n");

//	orthogonal(map);
}
