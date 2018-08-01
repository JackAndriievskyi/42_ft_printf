/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odhtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 08:44:21 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 09:30:56 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_countsize(size_t val, int base)
{
	size_t	res;

	res = 1;
	while ((val = val / base) > 0)
		res++;
	return (res);
}

static char		*ft_revstr(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < (size - i - 1))
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	return (str);
}

char			*ft_odhtostr(size_t val, int base)
{
	char	*res;
	size_t	size;
	size_t	i;

	size = ft_countsize(val, base);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	if (val == 0)
		res[i++] = '0';
	while (val)
	{
		if ((res[i] = val % base) < 10)
			res[i] += '0';
		else
			res[i] += ('a' - 10);
		i++;
		val /= base;
	}
	res[i] = 0;
	res = ft_revstr(res, size);
	return (res);
}
