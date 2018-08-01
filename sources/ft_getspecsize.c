/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspecsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:16:50 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/22 14:14:13 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_getspecsize(char **r_fmt, int *res)
{
	char	c;

	c = *(*r_fmt)++;
	if (c == 'h' && c == **r_fmt)
	{
		(*r_fmt)++;
		res[2] = 1;
	}
	else if (c == 'h')
		res[2] = 2;
	else if (c == 'l' && c == **r_fmt)
	{
		(*r_fmt)++;
		res[2] = 4;
	}
	else if (c == 'l')
		res[2] = 3;
	else if (c == 'j')
		res[2] = 5;
	else if (c == 'z')
		res[2] = 6;
	else
		(*r_fmt)--;
}
