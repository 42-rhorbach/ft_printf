/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_txt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 12:58:22 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/25 13:26:21 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	conv_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (ft_putchar_fd(c, STDOUT_FILENO));
}

int	conv_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_putstr_fd("(null)", STDOUT_FILENO));
	return (ft_putstr_fd(s, STDOUT_FILENO));
}

int	conv_percent(va_list ap)
{
	(void)ap;
	return (ft_putchar_fd('%', STDOUT_FILENO));
}
