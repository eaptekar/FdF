/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:32:50 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/27 19:19:24 by eaptekar         ###   ########.fr       */
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

t_map	map_get_points(t_map map, t_list *list)
{
	int	x_p;
	int	y_p;

	map.points = (t_point*)ft_memalloc(map.p_amount * sizeof(t_point));
	y_p = map.height - 1;
	while (y_p >= 0)
	{
		x_p = map.width - 1;
		while (x_p >= 0)
		{
			map.points[y_p * map.width + x_p] = 
				newpoint(x_p, y_p, *(int*)(list->content), list->color);
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
		colour = 0;
		while (**coords)
		{
			if (**coords == ',')
				colour = hex_to_int(*coords);
			(*coords)++;
		}
		if (!colour)
			colour = DEFAULT;
		ft_lstadd(list, ft_lstnew(&x_coord, colour, sizeof(int)));
		++coords;
	}
	return (width);
}
