/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getudecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:44:21 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/22 09:45:05 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nums.h"

char			*ft_getudecimal(char c, va_list *args, int *wdprss)
{
	t_nums	n;

	n.st = 0;
	if ((c == 'u' && wdprss[2] == 3) || c == 'U')
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
	return (ft_odhtostr(n.st, 10));
}
