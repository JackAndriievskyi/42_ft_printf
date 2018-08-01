/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsdecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:06:20 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 13:50:17 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nums.h"

static char		*ft_signhandle(size_t num)
{
	char	*tmp;
	char	*res;
	size_t	size;
	size_t	i;

	if (!(tmp = ft_odhtostr(num, 10)))
		return (NULL);
	size = 0;
	while (tmp[size])
		size++;
	if (!(res = (char *)malloc(sizeof(char) * (size + 2))))
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	res[i++] = '-';
	while (i < size + 2)
	{
		res[i] = tmp[i - 1];
		i++;
	}
	res[i] = 0;
	return (res);
}

char			*ft_getsdecimal(char c, va_list *args, int *wdprss)
{
	t_nums	n;

	n.st = 0;
	if (((c == 'i' || c == 'd') && wdprss[2] == 3) || c == 'D')
		if ((n.li = (long)va_arg(*args, long)) < 0)
			return (ft_signhandle(GLONG(n.li)));
	if (wdprss[2] == 1 && c != 'D')
		if ((n.c = (char)va_arg(*args, int)) < 0)
			return (ft_signhandle(GCHR(n.c)));
	if (wdprss[2] == 2 && c != 'D')
		if ((n.si = (short)va_arg(*args, int)) < 0)
			return (ft_signhandle(GSINT(n.si)));
	if (wdprss[2] == 4 && c != 'D')
		if ((n.lli = (long long)va_arg(*args, long long)) < 0)
			return (ft_signhandle(GLLONG(n.lli)));
	if (wdprss[2] == 5 && c != 'D')
		if ((n.imt = (intmax_t)va_arg(*args, intmax_t)) < 0)
			return (ft_signhandle(GINTMAX(n.imt)));
	if (wdprss[2] == 6 && c != 'D')
		if ((n.imt = (intmax_t)va_arg(*args, intmax_t)) < 0)
			return (ft_signhandle(GINTMAX(n.imt)));
	if (wdprss[2] == 0 && c != 'D')
		if ((n.i = (int)va_arg(*args, int)) < 0)
			return (ft_signhandle(GINT(n.i)));
	return (ft_odhtostr(n.st, 10));
}
