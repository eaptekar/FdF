/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:49:41 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/31 19:50:06 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS
//CHECK ALL NULL RETURNS

static int		accept_changes(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	transform(map);
	draw_map(map);
	return (0);
}

static int		deal_key(int key, t_map *map)
{
	if (key == 53)
		exit(1);
	else if (key == 0)
		rotate_x(map, map->ang);
	else if (key == 2)
		rotate_x(map, -(map->ang));
	else if (key == 13)
		rotate_y(map, map->ang);
	else if (key == 1)
		rotate_y(map, -(map->ang));
	else if (key == 12)
		rotate_z(map, map->ang);
	else if (key == 14)
		rotate_z(map, -(map->ang));
	return (0);
}

static int		no_key(int key, t_map *map)
{
	if (key == 0 || key == 2)
		rotate_x(map, 0);
	if (key == 13 || key == 1)
		rotate_y(map, 0);
	if (key == 12 || key == 14)
		rotate_z(map, 0);
	return (0);
}

static int		exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

void	scr_size(t_map *map)
{

	if (map->p_amount <= 1000)
	{
		map->scr_w = SCR_W_M;
		map->scr_h = SCR_H_M;
	}
	else
	{
		map->scr_w = SCR_W_L;
		map->scr_h = SCR_H_L;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	
	fd = map_get(argc, argv);
	map = map_create(fd);
	close(fd);
	transform(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.scr_w, map.scr_h, "FdF");
	draw_map(&map);
	map.ang = ANGLE * (M_PI / 180);
	mlx_hook(map.win_ptr, 17, 1L << 17, exit_x, &map);
	mlx_hook(map.win_ptr, 2, 1, deal_key, &map);
	mlx_hook(map.win_ptr, 3, 2, no_key, &map);
	mlx_loop_hook(map.mlx_ptr, accept_changes, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}