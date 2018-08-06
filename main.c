/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:49:41 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 15:47:59 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS
//CHECK ALL NULL RETURNS

static int		accept_changes(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	// render(map);
	draw_map(map);
	return (0);
}

static int		deal_key(int key, t_map *map)
{
	map->alpha >= 360 ? map->alpha -= 360 : (0);
	map->beta >= 360 ? map->beta -= 360 : (0);
	map->gamma >= 360 ? map->gamma -= 360 : (0);
	map->alpha <= -360 ? map->alpha += 360 : (0);
	map->beta <= -360 ? map->beta += 360 : (0);
	map->gamma <= -360 ? map->gamma += 360 : (0);
	if (key == 53)
	{
		// system("leaks fdf");
		exit(1);
	}
	else if (key == 0)
		map->alpha++;
	else if (key == 2)
		map->alpha--;
	else if (key == 13)
		map->beta++;
	else if (key == 1)
		map->beta--;
	else if (key == 12)
		map->gamma++;
	else if (key == 14)
		map->gamma--;
	return (0);
}

// static int		no_key(int key, t_map *map)
// {
// 	if (key == 0 || key == 2)
// 		rotate_x(map, 0);
// 	if (key == 13 || key == 1)
// 		rotate_y(map, 0);
// 	if (key == 12 || key == 14)
// 		rotate_z(map, 0);
// 	return (0);
// }

static int		exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

/*
** Use it in transform.c
** Also need to write reset function
*/
void	reset(t_map *map)
{
	scr_size(map);
	map->alpha = 69;
	map->beta = -13;
	map->gamma = 0;
	map->z_size = 1;
	map->center.x = (map->points[0].x + map->points[map->p_amount - 1].x) / 2;
	map->center.y = (map->points[0].y + map->points[map->p_amount - 1].y) / 2;  //CHECK THIS STUFF
	// if (map->z_size > 100 || map->z_size <= 0)  //PUT THIS IN RIGHT PLACE
	// 	map->z_size = 1;
}

void	scr_size(t_map *map)
{
	if (map->width > map->height)
	{
		map->scr_w = map->width * 10;
		if (map->scr_w < 800)
			map->scr_w = 800;
		else if (map->scr_w > 1920)
			map->scr_w = 1920;
		map->scr_h = (map->scr_w * 9) / 16;
		map->xscale = map->scr_w / (map->width + 1);
	}
	else
	{
		map->scr_h = map->height * 10;
		if (map->scr_h < 450)
			map->scr_h = 450;
		else if (map->scr_h > 1080)
			map->scr_h = 1080;
		map->scr_w = (map->scr_h * 16) / 9;
		map->scale = map->scr_h / map->height;
	}
	if (!map->scale)
		map->scale = 2;
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = map_open(argc, argv);
	map = map_create(fd);
	close(fd);
	reset(&map);
	// render(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.scr_w, map.scr_h, "FdF");
	map.ang = deg_to_rad(ANGLE);
	ft_putstr("\t\033[32m ✔ \033[32m\n");
	draw_map(&map);  // IT WAS draw_map before
	mlx_hook(map.win_ptr, 17, 1L << 17, exit_x, &map);
	mlx_hook(map.win_ptr, 2, 1, deal_key, &map);
	// mlx_hook(map.win_ptr, 3, 2, no_key, &map);
	mlx_loop_hook(map.mlx_ptr, accept_changes, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
