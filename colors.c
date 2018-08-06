/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:39:08 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 20:39:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_redcolor(t_map *map)
{
	size_t	i;

	i = 0;
	if (i < map->p_amount)
	{
		map->points[i].color = 0xC0392B;
		i++;
	}
}

void	key_greencolor(t_map *map)
{
	size_t	i;

	i = 0;
	if (i < map->p_amount)
	{
		map->points[i].color = 0x27AE60;
		i++;
	}
}

void	key_bluecolor(t_map *map)
{
	size_t	i;

	i = 0;
	if (i < map->p_amount)
	{
		map->points[i].color = 0x2980B9;
		i++;
	}
}

void	key_purplecolor(t_map *map)
{
	size_t	i;

	i = 0;
	if (i < map->p_amount)
	{
		map->points[i].color = 0x9B59B6;
		i++;
	}
}

void	key_yellowcolor(t_map *map)
{
	size_t	i;

	i = 0;
	if (i < map->p_amount)
	{
		map->points[i].color = 0xF1C40F;
		i++;
	}
}
