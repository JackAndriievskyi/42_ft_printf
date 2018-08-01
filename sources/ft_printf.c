/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:56:50 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/24 11:14:06 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iprintf.h"
#include "ft_printf.h"
#include <stdlib.h>

static int		ft_isflag(int c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '0')
		return (1);
	return (0);
}

static void		ft_bufhandle(char *buf, char **str, size_t *retval, size_t lim)
{
	size_t	i;

	i = *retval % PR_BUFF_SIZE;
	if (*str == NULL)
	{
		write(1, buf, i);
		*retval = SIZE_T_MAX;
		return ;
	}
	while ((**str && **str != '%') || lim != SIZE_T_MAX)
	{
		buf[i] = *(*str)++;
		(*retval)++;
		if ((i + 1) % PR_BUFF_SIZE == 0)
		{
			write(1, buf, PR_BUFF_SIZE);
			i = 0;
		}
		else
			i++;
		if (lim != SIZE_T_MAX)
			lim--;
	}
}

static size_t	ft_cntsize(char *str, char c, int width)
{
	size_t	i;

	i = 0;
	if (!str)
		return (SIZE_T_MAX);
	if (c == 'c' && width > 0)
		return (width);
	if (c == 'c')
		return (1);
	if (c == 'C' && str[0] == 0 && width > 0)
		return (width);
	if (c == 'C' && str[0] == 0)
		return (1);
	while (str[i])
		i++;
	return (i);
}

static void		ft_fmt(char *buf, char **r_fmt, va_list *args, size_t *retval)
{
	char			*tmp;
	char			*res;
	int				wdprss[3];
	size_t			size;

	if (!(**r_fmt))
		return ;
	tmp = *r_fmt;
	while (ft_isflag(*tmp))
		tmp++;
	wdprss[2] = 0;
	ft_getwidthprec(&tmp, wdprss);
	ft_getspecsize(&tmp, wdprss);
	res = ft_getdata(&tmp, args, wdprss);
	res = ft_makeflags(r_fmt, res, wdprss, *(tmp - 1));
	size = ft_cntsize(res, *(tmp - 1), wdprss[0]);
	*r_fmt = tmp;
	tmp = res;
	ft_bufhandle(buf, &res, retval, size - 1);
	if (*retval != SIZE_T_MAX)
		free(tmp);
}

int				ft_printf(char *format, ...)
{
	va_list			args;
	size_t			retval;
	char			resbuf[PR_BUFF_SIZE];

	va_start(args, format);
	retval = 0;
	while (*format && retval != SIZE_T_MAX)
	{
		ft_bufhandle(resbuf, &format, &retval, SIZE_T_MAX);
		if (retval != SIZE_T_MAX && *format)
		{
			format++;
			ft_fmt(resbuf, &format, &args, &retval);
		}
	}
	if (retval != SIZE_T_MAX)
		write(1, resbuf, retval % PR_BUFF_SIZE);
	va_end(args);
	return ((int)retval);
}
