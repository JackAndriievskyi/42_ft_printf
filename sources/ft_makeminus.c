/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeminus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 09:01:12 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 09:06:12 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_makeminus(char *str, size_t size, int width)
{
	size_t	i;

	if (size >= (size_t)width)
		return (str);
	i = 0;
	while (i < size)
	{
		str[i] = str[width - size + i];
		i++;
	}
	while (i < (size_t)width)
		str[i++] = ' ';
	str[i] = 0;
	return (str);
}
