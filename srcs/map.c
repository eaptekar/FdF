/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:28:43 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/08 14:44:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				map_open(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_putendl_exit("usage: ./fdf <map_name.fdf>", 0);
	if (!ft_strstr(argv[1], ".fdf"))
		ERROR("No data found.");
	if (!(fd = open(argv[1], O_RDONLY)))
		ERROR(strerror(errno));
	if ((read(fd, NULL, 0)) < 0)
		ERROR(strerror(errno));
	return (fd);
}

static t_point	newpoint(int x, int y, int z, long int color)
{
	t_point	point;

	point.x = 20 * x;
	point.y = 20 * y;
	point.z = 5 * z;
	point.colour = color;
	return (point);
}

static t_map	map_get_points(t_map map, t_list *list)
{
	int	x_p;
	int	y_p;

	if (!(map.points = ft_memalloc(map.p_amount * sizeof(t_point))))
		ERROR(strerror(errno));
	y_p = map.height - 1;
	while (y_p >= 0)
	{
		x_p = map.width - 1;
		while (x_p >= 0)
		{
			map.points[y_p * map.width + x_p] =\
				newpoint(x_p, y_p, *(int*)(list->content), list->color);
			x_p--;
			list = list->next;
		}
		y_p--;
	}
	return (map);
}

static void		del_node(void *item, size_t size)
{
	size = 0;
	free(item);
}

t_map			map_create(int fd)
{
	char	*line;
	size_t	width;
	t_list	*list;
	t_map	map;

	ft_putstr("\033[0mParsing... \033[0m");
	list = NULL;
	map.height = 0;
	ft_bzero(&map, sizeof(t_map));
	while (get_next_line(fd, &line))
	{
		width = parse_line(line, &list, 0);
		free(line);
		if (map.width == 0)
			map.width = width;
		else if (map.width != width)
			ERROR("Line lenght error");
		map.height++;
	}
	if (!(map.p_amount = map.width * map.height))
		ERROR("No data found.");
	map = map_get_points(map, list);
	ft_lstdel(&list, &del_node);
	ft_putstr("\t\033[32m ✔ \033[32m\n\033[0mRendering... \033[0m");
	return (map);
}
