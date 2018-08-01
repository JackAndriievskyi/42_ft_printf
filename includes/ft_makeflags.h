/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeflags.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 09:39:21 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/23 16:17:08 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAKEFLAGS_H
# define FT_MAKEFLAGS_H

# include <stdlib.h>

char	*ft_makeprec(char *str, int prec, char c);
char	*ft_makewidth(char *str, int width, char c);
char	*ft_makehasho(char *str, size_t *size);
char	*ft_makehashx(char *str, char c, size_t *size, int prec);
char	*ft_makezero(char *str, size_t size);
char	*ft_makeminus(char *str, size_t size, int width);
char	*ft_makespace(char *str, size_t *size, int prec, char c);
char	*ft_makeplus(char *str, size_t *size, int prec, char c);

#endif
