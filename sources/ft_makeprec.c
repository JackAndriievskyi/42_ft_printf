/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeprec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:40:03 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:55:57 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_iszero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
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

static char		*ft_sitrealloc(char *str, int prec, size_t size)
{
	char	*res;
	size_t	i;

	if (str[0] == '-')
		prec++;
	if (!(res = (char *)malloc(sizeof(char) * (prec + 1))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	if (str[i] == '-')
		res[i++] = '-';
	while (i < prec - size)
		res[i++] = '0';
	while (i <= (size_t)prec)
	{
		if (str[i - prec + size] == '-')
			res[i] = '0';
		else
			res[i] = str[i - prec + size];
		i++;
	}
	free(str);
	return (res);
}

char			*ft_makeprec(char *str, int prec, char c)
{
	size_t	size;
	int		sign;

	if (!str)
		return (NULL);
	if (c == 'p' || c == 'c' || c == 'C' || c == '%' || prec == (-1))
		return (str);
	size = 0;
	while (str[size])
		size++;
	if ((c == 's' && size < (size_t)prec) || (c == 'S' && prec != 0))
		return (str);
	else if (c == 's' || c == 'S' || (ft_iszero(str) && prec == 0))
	{
		str[prec] = 0;
		return (str);
	}
	sign = 0;
	if (str[0] == '-')
		sign++;
	if (c != 's' && (size - sign) >= (size_t)prec)
		return (str);
	return (ft_sitrealloc(str, prec, size));
}
