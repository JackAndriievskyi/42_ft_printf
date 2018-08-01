/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makehasho.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:23:11 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/21 13:55:40 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_osit1(char *str)
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
	str[0] = '0';
	return (str);
}

static char		*ft_osit2(char *str, size_t *inc)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (*inc + 2))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	res[i++] = '0';
	while (i < *inc + 1)
	{
		res[i] = str[i - 1];
		i++;
	}
	res[i] = '\0';
	(*inc)++;
	return (res);
}

char			*ft_makehasho(char *str, size_t *size)
{
	size_t	sspc;
	size_t	espc;

	sspc = 0;
	while (str[sspc] == ' ')
		sspc++;
	espc = 0;
	while (str[sspc + *size + espc] == ' ')
		espc++;
	if (str[sspc] == '0')
		return (str);
	if (sspc > 0 && espc == 0)
		str[sspc - 1] = '0';
	else if (sspc == 0 && espc > 0)
		return (ft_osit1(str));
	else if (sspc == 0 && espc == 0)
		return (ft_osit2(str, size));
	return (str);
}
