/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unifuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:53:38 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 14:04:14 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unifuncs.h"

size_t	ft_cntunisize(int val)
{
	int		check;

	check = val;
	if (check < 0 || check > 0x10FFFF || (check >= 0xD800 && check <= 0xDFFF))
		return (-1);
	check = val >> 7;
	if (check <= 0)
		return (1);
	check = val >> 11;
	if (check <= 0 && MB_CUR_MAX > 1)
		return (2);
	check = val >> 16;
	if (check <= 0 && MB_CUR_MAX > 1)
		return (3);
	check = val >> 21;
	if (check <= 0 && MB_CUR_MAX > 1)
		return (4);
	return (-1);
}

void	ft_unitochr(char *res, int val, size_t *size)
{
	size_t	swch;

	swch = ft_cntunisize(val);
	if (swch == 1)
		res[(*size)++] = (char)val;
	if (swch == 2)
	{
		res[(*size)++] = (char)((val >> 6) + 128 + 64);
		res[(*size)++] = (char)(val % 64 + 128);
	}
	if (swch == 3)
	{
		res[(*size)++] = (char)((val >> 12) + 128 + 64 + 32);
		res[(*size)++] = (char)((val >> 6) % 64 + 128);
		res[(*size)++] = (char)(val % 64 + 128);
	}
	if (swch == 4)
	{
		res[(*size)++] = (char)((val >> 18) + 128 + 64 + 32 + 16);
		res[(*size)++] = (char)((val >> 12) % 64 + 128);
		res[(*size)++] = (char)((val >> 6) % 64 + 128);
		res[(*size)++] = (char)(val % 64 + 128);
	}
}
