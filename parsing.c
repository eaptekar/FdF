/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:32:50 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/25 20:59:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NEED TO FREE COORDS

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