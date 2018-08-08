/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:35:19 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/08 17:33:36 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_legend(t_map *map)
{
	char	*speed;

	speed = ft_itoa(map->speed / 2);
	draw_frame(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 11, 0x80AAFF,
		"Rotate X with W or S");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 31, 0xAA80FF,
		"Rotate Y with A or D");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 51, 0x80FFAA,
		"Rotate Z with Q or E");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 71, 0xAAFF80,
		"Moving with arrows");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, map->scr_h - 51, 0xD7BDE2,
		"Change speed with [ or ]");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, map->scr_h - 31, 0xE6B0AA,
		"Change zoom with + or - on Numpad");
	mlx_string_put(map->mlx_ptr, map->win_ptr, map->scr_w - 121, 11, 0xFFAA80,
		"Exit = Esc");
	mlx_string_put(map->mlx_ptr, map->win_ptr, map->scr_w - 101, \
		map->scr_h - 31, 0xFF80AA, "Speed: ");
	mlx_string_put(map->mlx_ptr, map->win_ptr, map->scr_w - 31, \
		map->scr_h - 31, 0xFF80AA, speed);
	free(speed);
}

static int		pixel2image(t_map *map, int x, int y, int colour)
{
	char			*pixel;
	int				bpp;
	int				size_line;
	int				endian;

	if (x >= map->scr_w - 20 || x < 1 || y >= map->scr_h - 20 || y < 1)
		return (1);
	pixel = mlx_get_data_addr(map->img_ptr, &bpp, &size_line, &endian);
	ft_memmove((void*)(&pixel[y * size_line + \
		x * (bpp / 8)]), (void*)&colour, 4);
	return (0);
}

static void		drawing_line(t_map *map, t_point a, t_point b)
{
	double x;
	double y;

	x = a.x;
	y = a.y;
	if (fabs(b.y - a.y) > fabs(b.x - a.x))
	{
		while (a.y > b.y ? y >= b.y : y <= b.y)
		{
			x = (y - a.y) / (b.y - a.y) * (b.x - a.x) + a.x;
			pixel2image(map, x, y, a.colour);
			b.y > a.y ? y++ : y--;
		}
	}
	else
	{
		while (a.x > b.x ? x >= b.x : x <= b.x)
		{
			y = (x - a.x) / (b.x - a.x) * (b.y - a.y) + a.y;
			pixel2image(map, x, y, a.colour);
			b.x > a.x ? x++ : x--;
		}
	}
}

void			render(t_map *map)
{
	size_t	i;
	size_t	w;
	size_t	h;

	i = 0;
	h = 0;
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->scr_w - 10, \
		map->scr_h - 10);
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (w < map->width - 1)
				drawing_line(map, map->points[i], map->points[i + 1]);
			if (h < map->height - 1)
				drawing_line(map, map->points[i], map->points[i + map->width]);
			w++;
			i++;
		}
		h++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 10, 10);
	put_legend(map);
}
