/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:04:34 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:03:16 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IPRINTF_H
# define FT_IPRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_getwidthprec(char **r_fmt, int *res);
void	ft_getspecsize(char **r_fmt, int *res);
char	*ft_getdata(char **r_fmt, va_list *args, int *wdprss);
char	*ft_makeflags(char **r_fmt, char *str, int *wdprss, char c);

#endif
