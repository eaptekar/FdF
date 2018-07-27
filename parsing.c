/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:32:50 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/27 17:55:55 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS
//CHECK ALL NULL RETURNS

t_point	newpoint(int x, int y, int z, int colour)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.colour = colour;
	return (point);
}

t_map	map_points(t_map map, t_list *list)
{
	int	x_p;
	int	y_p;
	int	z_p;

	map.points = (t_point)ft_memalloc(map.p_amount * sizeof(t_point));
	y_p = map.height;
	while (y_p >= 0)
	{
		x_p = map.width;
		while (x_p >= 0)
		{
			map.points[y_p * map.width + x_p] = 
				newpoint(x_p, y_p, (int*)(list->content), list->color);
			x_p--;
			list = list->next;
		}
		y_p--;
	}
	return (map);
}

size_t	parse_line(char *line, t_list **list)
{
	size_t	width;
	char	**coords;
	int		x_coord;
	int		colour;

	width = 0;
	coords = ft_strsplit(line, ' ');
	while (*coords)
	{
		width++;
		x_coord = ft_atoi(*coords);
		while (**coords)
		{
			if (**coords == ',')
				colour = hex_to_int(*coords);
			else
				colour = DEFAULT;
			(*coords)++;
		}
//		free(*coords);
		ft_lstadd(list, ft_lstnew(&x_coord, colour, sizeof(int)));
		++coords;
	}
//	free(coords);
	return (width);
}
