/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:14:42 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/18 16:43:05 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	conv_c(va_list ap) //write can fail
{
	char	c;

	c = va_arg(ap, char);
	ft_putchar_fd(c, STDOUT_FILENO);
	return (0);
}

int	conv_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, STDOUT_FILENO);
	return (0);
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
	ft_putstr_fd(ft_itoa(i), STDOUT_FILENO);
	return (0);
}

int	conv_u(va_list ap) //WIP
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_putstr_fd(ft_itoa(u), STDOUT_FILENO);
	return (0);
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
			ft_putchar_fd(fmt[i], STDOUT_FILENO);
		i++;
	}
	va_end(ap);
}

int main (void)
{
	ft_printf("%c hello %s %i %u %x \n", 'a', "bye", 346, -200, 0xaf54a);
	printf("%c hello %s %i %u %x \n", 'a', "bye", 346, -200, 0xaf54a);
}
