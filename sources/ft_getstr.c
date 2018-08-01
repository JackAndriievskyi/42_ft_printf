/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:08:59 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/22 13:03:50 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unifuncs.h"

static char		*ft_getnullstr(void)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 7)))
		return (NULL);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = 0;
	return (res);
}

static char		*ft_getdefstr(char *str)
{
	char	*res;
	size_t	size;
	size_t	i;

	size = 0;
	while (str[size])
		size++;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char		*ft_getunistr(int *str)
{
	char	*res;
	size_t	size;
	size_t	tmp;
	size_t	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if ((tmp = ft_cntunisize(str[i])) == (size_t)(-1))
			return (NULL);
		size += tmp;
		i++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (str[i])
		ft_unitochr(res, str[i++], &size);
	res[size] = 0;
	return (res);
}

char			*ft_getstr(char c, va_list *args, int *wdprss)
{
	char		*resc;
	int			*resi;

	if (c == 'S' || (c == 's' && wdprss[2] == 3))
	{
		resi = (int *)va_arg(*args, int *);
		if (resi)
			return (ft_getunistr(resi));
		else
			return (ft_getnullstr());
	}
	else
	{
		resc = (char *)va_arg(*args, char *);
		if (resc)
			return (ft_getdefstr(resc));
		else
			return (ft_getnullstr());
	}
}
