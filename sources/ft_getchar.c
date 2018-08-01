/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:31:14 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 14:20:34 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unifuncs.h"

static char		*ft_getdefchar(char val)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = val;
	res[1] = 0;
	return (res);
}

static char		*ft_getunichar(int val)
{
	char	*res;
	size_t	size;

	if (val < 0)
		return (NULL);
	if ((size = ft_cntunisize(val)) == (size_t)(-1))
	{
		if (val < 256)
			return (ft_getdefchar(val));
		return (NULL);
	}
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	ft_unitochr(res, val, &size);
	res[size] = 0;
	return (res);
}

char			*ft_getchar(char c, va_list *args, int *wdprss)
{
	char	resc;
	int		resi;

	if (c == 'C' || (c == 'c' && wdprss[2] == 3))
	{
		resi = (int)va_arg(*args, int);
		return (ft_getunichar(resi));
	}
	else
	{
		resc = (char)va_arg(*args, int);
		return (ft_getdefchar(resc));
	}
}
