/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:02:58 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/16 11:56:37 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETDATA_H
# define FT_GETDATA_H

# include <stdarg.h>

char	*ft_getpercent(char c);
char	*ft_getstr(char c, va_list *args, int *wdprss);
char	*ft_getchar(char c, va_list *args, int *wdprss);
char	*ft_getsdecimal(char c, va_list *args, int *wdprss);
char	*ft_getudecimal(char c, va_list *args, int *wdprss);
char	*ft_getoctal(char c, va_list *args, int *wdprss);
char	*ft_gethex(char c, va_list *args, int *wdprss);

#endif
