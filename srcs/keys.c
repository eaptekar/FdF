/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:58:59 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 22:07:15 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

static void	key_scale(int kcode, t_map *map)
{
	if (kcode == K_PLUS)
		scaling(map, 1.25);
	else if (kcode == K_MINUS)
		scaling(map, 0.8);
	else if (kcode == K_SPMINUS)
	{
		if (map->speed >= 4)
			map->speed -= 2;
	}
	else if (kcode == K_SPPLUS)
	{
		if (map->speed <= 28)
			map->speed += 2;
	}
}

static void	key_shift(int kcode, t_map *map)
{
	if (kcode == K_LEFT)
		shifting(map, -map->speed, 0);
	if (kcode == K_RIGHT)
		shifting(map, map->speed, 0);
	if (kcode == K_DOWN)
		shifting(map, 0, map->speed);
	if (kcode == K_UP)
		shifting(map, 0, -map->speed);
}

static void	key_rotate(int kcode, t_map *map)
{
	if (kcode == K_W)
		rotating(map, 1, -map->speed);
	else if (kcode == K_S)
		rotating(map, 1, map->speed);
	else if (kcode == K_A)
		rotating(map, 2, -map->speed);
	else if (kcode == K_D)
		rotating(map, 2, map->speed);
	else if (kcode == K_Q)
		rotating(map, 3, -map->speed);
	else if (kcode == K_E)
		rotating(map, 3, map->speed);
}

int			key_hook(int kcode, t_map *map)
{
	centring(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	if (kcode == K_ESC)
		exit(1);
	else if (kcode >= K_LEFT && kcode <= K_UP)
		key_shift(kcode, map);
	else if ((kcode >= K_A && kcode <= K_D) || (kcode >= K_Q && kcode <= K_E))
	{
		key_rotate(kcode, map);
		key_change_angle(kcode, map);
	}
	else if (kcode == K_PLUS || kcode == K_MINUS)
		key_scale(kcode, map);
	else if (kcode == K_SPMINUS || kcode == K_SPPLUS)
		key_scale(kcode, map);
	render(map);
	return (0);
}
