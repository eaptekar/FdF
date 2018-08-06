/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:18:33 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 21:00:57 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = map_open(argc, argv);
	map = map_create(fd);
	ft_putstr("\t\033[32m ✔ \033[32m\n");
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, "FdF");
	centring(&map);
	moving_centre(&map);
	free(map.centre);
	getting_pic(&map);
	mlx_hook(map.win_ptr, 2, 5, key_hook, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
