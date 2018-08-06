/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:21:38 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/06 14:20:15 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS BEFORE EXIT
//CHECK ALL NULL RETURNS

static int			pixel2image(t_map *map, t_point a)
{
	char			*pixel;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;

	if (a.x >= map->scr_w || a.x < 0 || a.y >= map->scr_h || a.y < 0)
		return (1);
	pixel = mlx_get_data_addr(map->img_ptr, &bpp, &size_line, &endian);
	color = (mlx_get_color_value(map->mlx_ptr, a.colour));
	ft_memmove((void*)(&pixel[a.y * size_line + a.x * (bpp / 8)]), (void*)&color, 4);
	return (0);
}

/*static void		str_line(t_map *map, t_point2d a, t_point2d b)
{
	if (a.x == b.x)
	{
		while (a.y != b.y)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
			(a.y < b.y) ? a.y++ : a.y--;
		}
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
	}
	else
	{
		while (a.x != b.x)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
			(a.x < b.x) ? a.x++ : a.x--;
		}
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, a.colour);
	}
}

static void		diag_line_x(t_map *map, t_point temp, t_point2d start, float error)
{
	float	dot_y;
	t_point	a;

	dot_y = start.y;
	a.x = temp.x;
	a.y = dot_y;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, start.colour);
	while (temp.x <= temp.y)
	{
		a.x = temp.x;
		a.y = dot_y;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, start.colour);
		dot_y += error;
		temp.x++;
	}
}

static void		diag_line_y(t_map *map, t_point temp, t_point2d start, float error)
{
	float	dot_x;
	t_point	a;

	dot_x = start.x;
	a.y = temp.y;
	a.x = dot_x;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, start.colour);
	while (temp.x <= temp.y)
	{
		a.y = temp.y;
		a.x = dot_x;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, start.colour);
		dot_x += error;
		temp.x++;
	}
}

static void	bresenham_line(t_map *map, t_point2d a, t_point2d b)
{
	float		error;
	t_point		temp;

	if (a.x == b.x || a.y == b.y)
		str_line(map, a, b);
	else if(ft_abs(b.y - a.y) < ft_abs(b.x - a.x))
	{
		error = ((float)(b.y - a.y)) / (b.x - a.x);
		temp.x = (a.x < b.x) ? a.x : b.x;
		temp.y = (a.x > b.x) ? a.x : b.x;
		diag_line_x(map, temp, (a.x < b.x) ? a : b, error);
	}
	else
	{
		error = ((float)(b.x - a.x)) / (b.y - a.y);
		temp.x = (a.y < b.y) ? a.y : b.y;
		temp.y = (a.y > b.y) ? a.y : b.y;
		diag_line_y(map, temp, (a.y < b.y) ? a : b, error);
	}
}*/

/*static void	bresenham_line(t_map *map, t_point2d p0, t_point2d p1)
{
	double x;
	double y;

	x = p0.x;
	y = p0.y;
	if (ft_abs(p1.y - p0.y) > ft_abs(p1.x - p0.x))
	{
		while (p0.y > p1.y ? y >= p1.y : y <= p1.y)
		{
			x = ((y - p0.y) / (p1.y - p0.y) * (p1.x - p0.x) + p0.x);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0.colour);
			p1.y > p0.y ? y++ : y--;
		}
	}
	else
	{
		while (p0.x > p1.x ? x >= p1.x : x <= p1.x)
		{
			y = ((x - p0.x) / (p1.x - p0.x) * (p1.y - p0.y) + p0.y);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0.colour);
			p1.x > p0.x ? x++ : x--;
		}
	}
}*/

static void	bresenham_line(t_map *map, t_point a, t_point b)
{
	int		err;
	t_point	px;

	err = 0;
	px.y = a.y;
	px.x = a.x;
	px.colour = a.colour;
	while (px.x != b.x)
	{
		pixel2image(map, px);
		err += ft_abs(b.y - a.y);
		if ((err * 2) >= ft_abs(b.x - a.x))
		{
			px.y += ((b.y - a.y) > 0 ? 1 : -1);
			err -= ft_abs(b.x - a.x);
		}
		b.x > a.x ? px.x++ : px.x--;
	}
	while (px.y != b.y && a.x == b.x)
	{
		pixel2image(map, px);
		b.y > a.y ? px.y++ : px.y--;
	}
}

static void	draw_lines(t_map *map)
{
	size_t	i;
	size_t	w;
	size_t	h;

	i = 0;
	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (w < map->width - 1)
				bresenham_line(map, map->points[i], map->points[i + 1]);
			if (h < map->height - 1)
				bresenham_line(map, map->points[i], \
					map->points[i + map->width]);
			w++;
			i++;
		}
		h++;
	}
}

t_point		make_t2(int x, int y)
{
	t_point	a;

	a.x = x;
	a.y = y;
	a.colour = WHITE;
	return (a);
}

static void	put_legend(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 11, 0x80AAFF,
		"Rotate X = A or D");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 31, 0xAA80FF,
		"Rotate Y = W or S");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 12, 51, 0x80FFAA,
		"Rotate Z = Q or E");
	mlx_string_put(map->mlx_ptr, map->win_ptr, map->scr_w - 151, 11, 0xFFAA80,
		"Exit = Esc");
}

void		draw_map(t_map *map)
{
	render(map);
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->scr_w, map->scr_h);
	bresenham_line(map, make_t2(10, 10), make_t2(10, map->scr_h - 10));
	bresenham_line(map, make_t2(map->scr_w - 10, 10), \
		make_t2(map->scr_w - 10, map->scr_h - 10));
	bresenham_line(map, make_t2(10, 10), make_t2(map->scr_w - 10, 10));
	bresenham_line(map, make_t2(10, map->scr_h - 10), \
		make_t2(map->scr_w - 10, map->scr_h - 10));
	draw_lines(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	put_legend(map);
}
