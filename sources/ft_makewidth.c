/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthmake.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:11:51 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 10:03:42 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_sitrealloc(char *str, int width, size_t size)
{
	char	*res;
	size_t	i;

	if (!(res = (char *)malloc(sizeof(char) * (width + 1))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < width - size)
		res[i++] = ' ';
	while (i < (size_t)width)
	{
		res[i] = str[size + i - width];
		i++;
	}
	res[i] = 0;
	free(str);
	return (res);
}

char			*ft_makewidth(char *str, int width, char c)
{
	size_t	size;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size])
		size++;
	if ((c == 'c' || c == 'C') && str[0] == 0)
		size++;
	if (size >= (size_t)width || width == 0)
		return (str);
	return (ft_sitrealloc(str, width, size));
}
