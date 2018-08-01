/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:48:20 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:16:10 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_iszero(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] == ' ')
		i++;
	j = 0;
	while (str[i + j] == '0')
		j++;
	if (!str[i + j] || str[i + j] == ' ')
		return (0);
	if (str[i + j] >= '0' && str[i + j] <= '9')
		if (j == 0)
			return (0);
	if (str[i + j] >= 'a' && str[i + j] <= 'f')
		if (j == 0)
			return (0);
	if (str[i + j] >= 'A' && str[i + j] <= 'F')
		if (j == 0)
			return (0);
	return (1);
}

static char		*ft_plussit1(char *str)
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
	str[0] = '+';
	return (str);
}

static char		*ft_plussit2(char *str, size_t *inc)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (*inc + 2))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	res[i++] = '+';
	while (i < *inc + 1)
	{
		res[i] = str[i - 1];
		i++;
	}
	res[i] = 0;
	(*inc)++;
	free(str);
	return (res);
}

char			*ft_makeplus(char *str, size_t *size, int prec, char c)
{
	size_t	sspc;
	size_t	espc;

	if (c != 'i' && c != 'd' && c != 'D')
		return (str);
	sspc = 0;
	while (str[sspc] == ' ')
		sspc++;
	espc = 0;
	while (str[sspc + *size + espc] == ' ')
		espc++;
	if (str[sspc] == '+' || str[sspc] == '-')
		return (str);
	if (sspc > 0)
	{
		str[sspc - 1] = '+';
		(*size)++;
	}
	if (sspc == 0 && espc == 0 && prec == -1 && ft_iszero(str))
		str[0] = '+';
	else if (sspc == 0 && espc > 0)
		return (ft_plussit1(str));
	else if (sspc == 0 && espc == 0)
		return (ft_plussit2(str, size));
	return (str);
}
