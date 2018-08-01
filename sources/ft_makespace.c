/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 09:55:22 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:58:36 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_isnegative(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == '-')
			return (1);
	return (0);
}

static char		*ft_spacesit1(char *str)
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
	str[0] = tmpn;
	return (str);
}

static char		*ft_spacesit2(char *str, size_t *inc)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (*inc + 2))))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	res[i++] = ' ';
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

char			*ft_makespace(char *str, size_t *size, int prec, char c)
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
	if (sspc > 0 || ft_isnegative(str))
	{
		(*size)++;
		return (str);
	}
	if (sspc == 0 && espc == 0 && prec == -1 && str[0] == '0')
		str[0] = ' ';
	else if (sspc == 0 && espc > 0)
		return (ft_spacesit1(str));
	else if (sspc == 0 && espc == 0)
		return (ft_spacesit2(str, size));
	return (str);
}
