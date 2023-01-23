/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthnbr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 16:35:53 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/23 16:53:20 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

ssize_t	ft_puthnbr_fd(unsigned int n, int fd)
{
	ssize_t					count;
	static const char		s[] = "0123456789abcdef";

	count = 0;
	if (n > 9)
		count = ft_puthnbr_fd((n / 16), fd);
	if (count < 0)
		return (-1);
	if (ft_putchar_fd((n % 10) + 48, fd) < 0)
		return (-1);
	return (count + 1);
}
