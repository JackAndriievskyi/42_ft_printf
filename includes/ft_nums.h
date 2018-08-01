/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 08:40:09 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/22 13:57:36 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMS_H
# define FT_NUMS_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

# define GCHR(x) (x == SCHAR_MIN) ? ((size_t)SCHAR_MAX + 1) : (x * (-1))
# define GSINT(x) (x == SHRT_MIN) ? ((size_t)SHRT_MAX + 1) : (x * (-1))
# define GINT(x) (x == INT_MIN) ? ((size_t)INT_MAX + 1) : (x * (-1))
# define GLONG(x) (x == LONG_MIN) ? ((size_t)LONG_MAX + 1) : (x * (-1))
# define GLLONG(x) (x == LLONG_MIN) ? ((size_t)LLONG_MAX + 1) : (x * (-1))
# define GINTMAX(x) (x == INTMAX_MIN) ? ((size_t)INTMAX_MAX + 1) : (x * (-1))

typedef union				u_nums
{
	int						i;
	char					c;
	void					*vptr;
	short					si;
	long					li;
	long long				lli;
	intmax_t				imt;
	size_t					st;
	unsigned int			ui;
	unsigned char			uc;
	unsigned short			usi;
	unsigned long			uli;
	unsigned long long		ulli;
	uintmax_t				uimt;
}							t_nums;

char						*ft_odhtostr(long long int val, int base);

#endif
