/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:56:23 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/31 17:01:12 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS
//CHECK ALL NULL RETURNS

int		map_get(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_putendl_exit("usage: ./fdf <map file>", 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_putendl_exit(strerror(errno), -1);
	return (fd);
}


static t_point	newpoint(int x, int y, int z, int colour)
{
	t_point	point;

	point.x = 25 * x;
	point.y = 25 * y;
	point.z = 25 * z;
	point.colour = colour;
	return (point);
}

t_map			map_get_points(t_map map, t_list *list)
{
	int	x_p;
	int	y_p;

	map.points = ft_memalloc(map.p_amount * sizeof(t_point));
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

static void	del_node(void *item, size_t size)
{
	size = 0;
	free(item);
}

t_map	map_create(fd)
{
	t_list	*list;
	t_map	map;
	char	*line;
	size_t	width;

	list = NULL;
	map.height = 0;
	ft_bzero(&map, sizeof(t_map));
	while (get_next_line(fd, &line))
	{
		width = parse_line(line, &list);
		free(line);
		if (map.width == 0)
			map.width = width;
		else if (map.width != width)
			ft_putendl_exit("Line lenght error", -1);
		map.height++;
	}
	map.p_amount = map.width * map.height;
	map = map_get_points(map, list);
	ft_lstdel(&list, &del_node);
	return (map);
}
