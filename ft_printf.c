/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:14:42 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/24 17:04:08 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

// va_arg cannot accept char
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

int	conv_percent(va_list ap)
{
	(void)ap;
	return (ft_putchar_fd('%', STDOUT_FILENO));
}

typedef int	(*t_conversion_function)(va_list);

int call_jump_table(char c, va_list ap)
{
	static const t_conversion_function	jump_table[] = {
	['c'] = &conv_c,
	['s'] = &conv_s,
	['p'] = &conv_p,
	['d'] = &conv_i,
	['i'] = &conv_i,
	['u'] = &conv_u,
	['x'] = &conv_lowerx,
	['X'] = &conv_upperx,
	['%'] = &conv_percent
	};

	if (c != '\0' && ft_strchr("cspdiuxX%", c) != NULL)
		return (jump_table[(int)c](ap));
	else
		return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		out;

	i = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			out = call_jump_table(fmt[i], ap);
			if (out < 0)
				return (-1);
			count += out;
		}
		else
		{
			if (ft_putchar_fd(fmt[i], STDOUT_FILENO) < 0)
				return (-1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

int main (void)
{
	int address = 2;
	#define ARGS ("%c hello %s %p %i %u%x %X %% \n%", 'a', NULL, -0x10000000000, -0x80000000, 76579, -1, 0xAf54A)
	int reg = printf ARGS;
	fflush(NULL);
	int ft = ft_printf ARGS;
	printf("ft: %i\nreg: %i\n", ft, reg);
}
