/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:14:42 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/25 15:51:28 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_conv.h"
#include <stdarg.h>
#include <unistd.h>

// va_arg cannot accept char
int	call_jump_table(char c, va_list ap)
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

int	read_input(const char *fmt, va_list ap)
{
	int		i;
	int		count;
	int		out;

	i = 0;
	count = 0;
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
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = read_input(fmt, ap);
	va_end(ap);
	return (count);
}

// int main (void)
// {
// 	int address = 2;
// 	#define ARGS ("%c hello %s %p %i %u%x %X %% \n%", 'a', NULL, -0x10000000000, -0x80000000, 76579, -1, 0xAf54A)
// 	int reg = printf ARGS;
// 	fflush(NULL);
// 	int ft = ft_printf ARGS;
// 	printf("ft: %i\nreg: %i\n", ft, reg);
// }
