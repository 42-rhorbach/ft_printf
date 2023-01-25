/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 13:17:35 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/25 13:23:49 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <stdarg.h>

typedef int	(*t_conversion_function)(va_list);

int	conv_c(va_list ap);
int	conv_s(va_list ap);
int	conv_p(va_list ap);
int	conv_i(va_list ap);
int	conv_u(va_list ap);
int	conv_lowerx(va_list ap);
int	conv_upperx(va_list ap);
int	conv_percent(va_list ap);

#endif
