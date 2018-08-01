/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makezero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 08:50:51 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 14:47:41 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_zerosit(char *str, size_t sspc)
{
	size_t	i;

	i = 0;
	if (str[sspc] == '-' || str[sspc] == '+' || str[sspc] == ' ')
	{
		str[i++] = str[sspc];
		str[sspc] = '0';
	}
	else if (str[sspc] == '0' && (str[sspc + 1] == 'x' || str[sspc + 1] == 'X'))
	{
		str[i++] = str[sspc];
		str[i++] = str[sspc + 1];
		str[sspc + 1] = '0';
	}
	while (str[i] == ' ')
		str[i++] = '0';
	return (str);
}

char			*ft_makezero(char *str, size_t size)
{
	size_t	sspc;
	size_t	i;

	sspc = 0;
	while (str[sspc] == ' ')
		sspc++;
	if (sspc == 0)
		return (str);
	i = 0;
	while (str[sspc + i] != ' ' && str[sspc + i])
		i++;
	if (i == 0 && size != 0)
		i++;
	if (i < size)
		sspc--;
	return (ft_zerosit(str, sspc));
}
