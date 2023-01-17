/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:14:42 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/17 16:41:31 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	conv_c(va_list ap)
{
	char	c;

	c = va_arg(ap, char);
	write(1, &c, 1);
	return (0);
}

int	conv_s(va_list ap)
{
	char *s = va_arg(ap, char*);
	return (0);
}

int	conv_p(va_list ap)
{
	void *p = va_arg(ap, void *);
	return (0);
}

int	conv_i(va_list ap)
{
	int i = va_arg(ap, int);
	printf("%i\n", i);
	return (0);
}

int	conv_u(va_list ap)
{
	unsigned int u = va_arg(ap, unsigned int);
	return (0);
}

int	conv_lowerx(va_list ap)
{
	unsigned int x = va_arg(ap, unsigned int);
	return (0);
}

int	conv_upperx(va_list ap)
{
	unsigned int x = va_arg(ap, unsigned int);
	return (0);
}

int	conv_percent(va_list ap)
{
	// (void)ap;
	//
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

	if (ft_strchr("cspdiuxX%", c) != NULL)
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
	char	c;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		c = fmt[i];
		if (c == '%')
		{
			i++;
			call_jump_table(fmt[i], ap);
			// if return value != 0 error
		}
		else
		{

		}

		i++;
	}
	va_end(ap);
}

int main (void)
{
	ft_printf("%c hello %i", 'a', 457, "jahsd");

}
