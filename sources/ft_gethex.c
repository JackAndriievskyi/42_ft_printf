/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:44:21 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 13:27:06 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nums.h"

static char		*ft_alterhexp(char *str)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = 0;
	while (str[size])
		size++;
	size += 2;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
	{
		free(str);
		return (NULL);
	}
	res[0] = '0';
	res[1] = 'x';
	i = 0;
	while (str[i])
	{
		res[2 + i] = str[i];
		i++;
	}
	res[2 + i] = 0;
	free(str);
	return (res);
}

static char		*ft_alterhexx(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
	return (str);
}

static char		*ft_alterhex(char *str, char c)
{
	if (c == 'X')
		return (ft_alterhexx(str));
	if (c == 'p')
		return (ft_alterhexp(str));
	return (str);
}

char			*ft_gethex(char c, va_list *args, int *wdprss)
{
	t_nums	n;
	char	*res;

	n.st = 0;
	if (c == 'p')
		n.vptr = (void *)va_arg(*args, void *);
	else if (wdprss[2] == 3)
		n.uli = (unsigned long int)va_arg(*args, unsigned long int);
	else if (wdprss[2] == 1)
		n.uc = (unsigned char)va_arg(*args, int);
	else if (wdprss[2] == 2)
		n.usi = (unsigned short int)va_arg(*args, int);
	else if (wdprss[2] == 4)
		n.lli = (unsigned long long int)va_arg(*args, unsigned long long int);
	else if (wdprss[2] == 5)
		n.uimt = (uintmax_t)va_arg(*args, uintmax_t);
	else if (wdprss[2] == 6)
		n.st = (size_t)va_arg(*args, size_t);
	else if (wdprss[2] == 0)
		n.ui = (unsigned int)va_arg(*args, unsigned int);
	res = ft_odhtostr(n.st, 16);
	res = ft_alterhex(res, c);
	return (res);
}
