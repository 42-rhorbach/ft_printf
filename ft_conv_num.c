/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 12:58:22 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/25 15:51:19 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	conv_p(va_list ap)
{
	void	*p;
	int		count;

	p = va_arg(ap, void *);
	if (ft_putstr_fd("0x", STDOUT_FILENO) < 0)
		return (-1);
	count = ft_puthexnbr_fd((unsigned long)p, false, STDOUT_FILENO);
	if (count < 0)
		return (-1);
	return (count + 2);
}

int	conv_i(va_list ap)
{
	int		i;

	i = va_arg(ap, int);
	return (ft_putnbr_fd(i, STDOUT_FILENO));
}

int	conv_u(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	return (ft_putunbr_fd(u, STDOUT_FILENO));
}

int	conv_lowerx(va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	return (ft_puthexnbr_fd(x, false, STDOUT_FILENO));
}

int	conv_upperx(va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	return (ft_puthexnbr_fd(x, true, STDOUT_FILENO));
}
