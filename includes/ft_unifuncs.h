/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unifuncs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:50:52 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/13 08:42:24 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNIFUNCS_H
# define FT_UNIFUNCS_H

# include <stdlib.h>
# include <stdarg.h>

size_t	ft_cntunisize(int val);
void	ft_unitochr(char *res, int val, size_t *size);

#endif
