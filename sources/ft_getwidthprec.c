/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidthprec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:42:28 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/21 10:45:11 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_getwidthprec(char **r_fmt, int *res)
{
	int		tmp;

	tmp = 0;
	while (**r_fmt >= '0' && **r_fmt <= '9')
		tmp = tmp * 10 + *(*r_fmt)++ - '0';
	res[0] = tmp;
	if (**r_fmt == '.')
	{
		(*r_fmt)++;
		tmp = 0;
		while (**r_fmt >= '0' && **r_fmt <= '9')
			tmp = tmp * 10 + *(*r_fmt)++ - '0';
		res[1] = tmp;
	}
	else
		res[1] = -1;
}
