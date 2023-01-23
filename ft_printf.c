/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:14:42 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/23 13:47:00 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	conv_c(va_list ap)
{
	char	c;

	c = va_arg(ap, char);
	return (ft_putchar_fd(c, STDOUT_FILENO));
}

int	conv_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	return (ft_putstr_fd(s, STDOUT_FILENO));
}

int	conv_p(va_list ap) //WIP
{
	void	*p;

	p = va_arg(ap, void *);
	return (0);
}

int	conv_i(va_list ap)
{
	int		i;

	i = va_arg(ap, int);
	return (ft_putnbr_fd(i, STDOUT_FILENO));
}

int	conv_u(va_list ap) //WIP
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	return (ft_putunbr_fd(u, STDOUT_FILENO));
}

int	conv_lowerx(va_list ap) //WIP
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	return (0);
}

int	conv_upperx(va_list ap) //WIP
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	return (0);
}

int	conv_percent(va_list ap) //WIP
{
	// (void)ap;
	//ft_putchar_fd('%');
	return (0);
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

	if (ft_strchr("cspdiuxX%", c) != NULL) //output must be recognised as -1
	{
		return (jump_table[c](ap));
	}
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

#define ARGS ("%c hello %s %i %u %x \n", 'a', "bye", 346, 4294967297, 0xaf54a)

int main (void)
{
	int ft = ft_printf ARGS;
	int reg = printf ARGS;
	printf("ft: %i\nreg: %i\n", ft, reg);
}
