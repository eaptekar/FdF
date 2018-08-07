/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:18:33 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 22:18:09 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scr_size(t_map *map)
{
	if (map->width > map->height)
	{
		map->scr_w = map->width * 20;
		if (map->scr_w < 1200)
			map->scr_w = 1200;
		else if (map->scr_w > 2400)
			map->scr_w = 2400;
		map->scr_h = (map->scr_w * 9) / 16;
	}
	else
	{
		map->scr_h = map->height * 20;
		if (map->scr_h < 800)
			map->scr_h = 800;
		else if (map->scr_h > 1350)
			map->scr_h = 1350;
		map->scr_w = (map->scr_h * 16) / 9;
	}
}

void		ft_init(t_map *map)
{
	scr_size(map);
	centring(map);
	moving_center(map);
	map->speed = 10;
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = map_open(argc, argv);
	map = map_create(fd);
	ft_init(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.scr_w, map.scr_h, "FdF");
	ft_putstr("\t\033[32m ✔ \033[32m\n");
	ft_putendl("\n\e[0mPress [ESC] to quit FdF \e[0m\n");
	render(&map);
	mlx_hook(map.win_ptr, 17, 1L << 17, exit_x, &map);
	mlx_hook(map.win_ptr, 2, 0, key_hook, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
