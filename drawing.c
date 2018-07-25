/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:21:38 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/18 18:06:44 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham_line(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr)
{
	int		err;
	int		y;
	int		x;

	err = 0;
	y = y0;
	x = x0;
	while (x != x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, WHITE);
		err += ft_abs(y1 - y0);
		if ((err * 2) >= ft_abs(x1 - x0))
		{
			y += ((y1 - y0) > 0 ? 1 : -1);
			err -= ft_abs(x1 - x0);
		}
		x1 > x0 ? x++ : x--;
	}
	while (y != y1 && x0 == x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, WHITE);
		y1 > y0 ? y++ : y--;
	}
}

static int		deal_key(int key, void *param)
{
	if (key == 53)
		exit(1);
	param = NULL;
	return (0);
}

void	draw_map(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	bresenham_line(240, 250, 240, 250, mlx_ptr, win_ptr);
	bresenham_line(240, 250, 260, 250, mlx_ptr, win_ptr);
	bresenham_line(260, 250, 240, 250, mlx_ptr, win_ptr);
	bresenham_line(260, 250, 260, 250, mlx_ptr, win_ptr);
	bresenham_line(10, 10, 10, 490, mlx_ptr, win_ptr);
	bresenham_line(490, 490, 10, 490, mlx_ptr, win_ptr);
	bresenham_line(10, 490, 10, 10, mlx_ptr, win_ptr);
	bresenham_line(10, 490, 490, 490, mlx_ptr, win_ptr);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
