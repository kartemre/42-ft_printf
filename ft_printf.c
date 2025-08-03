/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:09:13 by ekart             #+#    #+#             */
/*   Updated: 2025/08/03 11:51:43 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_variadic(char c, va_list lst)
{
	if (c == 'c')
		return (ft_putchar(va_arg(lst, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_dec((long)va_arg(lst, int), BASE_10, 10));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(lst, unsigned long)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(lst, unsigned long), LOWER_BASE, 16));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(lst, unsigned long), UPPER_BASE, 16));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	lst;
	int		i;
	int		len;

	va_start(lst, input);
	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			len += ft_variadic(input[i], lst);
		}
		else
			len += write(1, &input[i], 1);
		i++;
	}
	va_end(lst);
	return (len);
}
