/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 08:25:22 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 11:43:01 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getdata.h"
#include <stdlib.h>

char	*ft_getdata(char **r_fmt, va_list *args, int *wdprss)
{
	char	c;
	char	*res;

	c = *(*r_fmt)++;
	if (c == '%')
		return (ft_getpercent(c));
	if (c == 's' || c == 'S')
		return (ft_getstr(c, args, wdprss));
	if (c == 'c' || c == 'C')
		return (ft_getchar(c, args, wdprss));
	if (c == 'i' || c == 'd' || c == 'D')
		return (ft_getsdecimal(c, args, wdprss));
	if (c == 'u' || c == 'U')
		return (ft_getudecimal(c, args, wdprss));
	if (c == 'o' || c == 'O')
		return (ft_getoctal(c, args, wdprss));
	if (c == 'x' || c == 'X' || c == 'p')
		return (ft_gethex(c, args, wdprss));
	if (!(res = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = c;
	res[1] = 0;
	return (res);
}
