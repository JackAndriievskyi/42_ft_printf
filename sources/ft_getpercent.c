/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:06:46 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/12 10:08:45 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_getpercent(char c)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = c;
	res[1] = 0;
	return (res);
}
