/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:48:57 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/15 15:56:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_is_color(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i + 1] == 48 && (str[i + 2] == 88 || str[i + 2] == 120))
	{
		i += 3;
		while (str && str[i])
		{
			if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && \
				str[i] <= 70) || (str[i] >= 97 && str[i] <= 102))
				i++;
			else
				return (0);
			j++;
		}
	}
	else
		return (0);
	if (j > 6)
		return (0);
	return (1);
}

static int		ft_valid_signs(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strchr(str, ','))
	{
		if (!ft_is_color(str))
			return (0);
	}
	else
	{
		while (str && str[i])
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
		free(str[i]);
		i++;
	}
	free(str);
}

size_t			parse_line(char *line, t_list **list, size_t j)
{
	size_t		width;
	char		**coords;
	int			x_coord;
	long int	colour;

	if (!line || line[0] == '\0' || line[0] == '\n')
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
