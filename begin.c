/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:40:59 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/27 19:19:10 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

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
	return (map);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;

size_t		i;
	t_point	p;

	fd = map_get(argc, argv);
	map = map_create(fd);
	close(fd);

	i = 0;
	while (i < map.p_amount)
	{
		p = map.points[i];
		printf("[%zu] (%d, %d, %d) %X\n", i, p.x, p.y, p.z, p.colour);
		i++;
	}

//	draw_map();
	return (0);
}
