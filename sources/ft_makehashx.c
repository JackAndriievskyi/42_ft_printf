/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makehash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:39:19 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:06:01 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_xsit1(char *str, char c, size_t *size)
{
	size_t	j;
	char	tmpp;
	char	tmpn;

	j = 0;
	tmpp = str[j];
	tmpn = str[j];
	while (str[j] != ' ')
	{
		str[j] = tmpp;
		tmpp = tmpn;
		tmpn = str[++j];
	}
	str[j] = tmpp;
	str[0] = c;
	(*size)++;
	return (str);
}

static char		*ft_xsit2(char *str, char c, size_t *size)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (*size + 3))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	res[i++] = '0';
	res[i++] = c;
	j = 0;
	if (str[j] == '0')
		j++;
	while (i < *size + 2)
	{
		res[i] = str[i - 2 + j];
		i++;
	}
	res[i] = 0;
	(*size) += (2 - j);
	free(str);
	return (res);
}

char			*ft_makehashx(char *str, char c, size_t *size, int prec)
{
	size_t	sspc;
	size_t	espc;

	sspc = 0;
	while (str[sspc] == ' ')
		sspc++;
	espc = 0;
	while (str[sspc + *size + espc] == ' ')
		espc++;
	if (sspc == 0 && espc == 0 && prec == -1 && str[0] == '0' && str[1] == '0')
		str[1] = c;
	else if (sspc > 1)
	{
		str[sspc - 1] = c;
		str[sspc - 2] = '0';
		*size += 2;
	}
	else if (espc > 1)
	{
		str = ft_xsit1(str, c, size);
		str = ft_xsit1(str, '0', size);
	}
	else if (sspc < 2 || espc < 2)
		return (ft_xsit2(str, c, size));
	return (str);
}
