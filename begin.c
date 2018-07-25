/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:40:59 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/25 20:59:39 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

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
	return (map);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = map_get(argc, argv);
	map = map_create(fd);
	close(fd);
	draw_map();
	return (0);
}
