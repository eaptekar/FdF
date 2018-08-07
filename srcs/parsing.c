/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:48:57 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 21:24:09 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_valid_signs(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_strchr(str, ','))
		{
			if (str[i] == 44 || str[i] == 45 || (str[i] >= 48 && str[i] <= 57) \
				|| (str[i] >= 65 && str[i] <= 70) || str[i] == 88 || \
				str[i] == 120 || (str[i] >= 97 && str[i] <= 102))
				i++;
			else
				return (0);
		}
		if (!ft_strchr(str, ','))
		{
			if (str[i] == 45 || (str[i] >= 48 && str[i] <= 57))
				i++;
			else
				return (0);
		}
	}
	return (1);
}

static void		clean_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_memdel((void *)&str[i++]);
	}
	ft_memdel((void *)&str);
}

size_t			parse_line(char *line, t_list **list, size_t j)
{
	size_t		width;
	char		**coords;
	int			x_coord;
	long int	colour;

	if (!line)
		ERROR("Failed to read file.");
	width = 0;
	if (!(coords = ft_strsplit(line, ' ')))
		ERROR("Failed to read file.");
	while (coords[j])
	{
		if (!ft_valid_signs(coords[j]))
			ERROR("Map error: wrong symbol has been found.");
		width++;
		x_coord = ft_atoi(coords[j]);
		if (ft_strchr(coords[j], ','))
			colour = hex_to_int(coords[j]);
		else
			colour = DEFAULT;
		ft_lstadd(list, ft_lstnew(&x_coord, colour, sizeof(int)));
		j++;
	}
	clean_array(coords);
	return (width);
}
