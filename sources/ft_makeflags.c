/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:35:52 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:16:45 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_makeflags.h"

static int	ft_isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static int	ft_iszero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] >= '1' && str[i] <= '9')
		return (0);
	if (str[i] >= 'a' && str[i] <= 'f')
		return (0);
	if (str[i] >= 'A' && str[i] <= 'F')
		return (0);
	return (1);
}

static int	ft_flaginfmt(char **r_fmt, char del)
{
	char	*save;

	save = *r_fmt;
	while (**r_fmt != '%')
		(*r_fmt)--;
	(*r_fmt)++;
	while (ft_isflag(**r_fmt))
	{
		if (**r_fmt == del)
		{
			*r_fmt = save;
			return (1);
		}
		(*r_fmt)++;
	}
	*r_fmt = save;
	return (0);
}

char		*ft_makeflags(char **r_fmt, char *str, int *wdprss, char c)
{
	size_t	size;

	if (!(str = ft_makeprec(str, wdprss[1], c)))
		return (NULL);
	size = 0;
	while (str[size] || ((c == 'c' || c == 'C') && size == 0))
		size++;
	str = ft_makewidth(str, wdprss[0], c);
	while (ft_isflag(**r_fmt) && str)
	{
		if (**r_fmt == '#' && (c == 'o' || c == 'O'))
			str = ft_makehasho(str, &size);
		else if (**r_fmt == '#' && !ft_iszero(str) && (c == 'x' || c == 'X'))
			str = ft_makehashx(str, c, &size, wdprss[1]);
		else if (**r_fmt == '0' && wdprss[1] == -1 && !ft_flaginfmt(r_fmt, '-'))
			str = ft_makezero(str, size);
		else if (**r_fmt == '-')
			str = ft_makeminus(str, size, wdprss[0]);
		else if (**r_fmt == ' ' && !ft_flaginfmt(r_fmt, '+'))
			str = ft_makespace(str, &size, wdprss[1], c);
		else if (**r_fmt == '+')
			str = ft_makeplus(str, &size, wdprss[1], c);
		(*r_fmt)++;
	}
	return (str);
}
