/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 14:37:18 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/24 13:24:50 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_intlen(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}

char	*ft_itoh(int n)
{
	static const char		s[] = "0123456789abcdef";
	char					*ptr;
	int						i;

	i = ft_intlen(n);
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i--;
	while (i != 0)
	{
		ptr[i] = s[n % 16];
		n /= 16;
		i--;
	}
	ptr[i] = s[n % 16];
	return (ptr);
}
