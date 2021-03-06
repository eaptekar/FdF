/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:59:10 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/06 16:20:16 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *temp;

	temp = s1;
	while (*temp)
		temp++;
	while ((*temp++ = *s2++))
		;
	return (s1);
}
