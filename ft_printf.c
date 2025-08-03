/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:09:13 by ekart             #+#    #+#             */
/*   Updated: 2025/08/03 10:35:14 by ekart            ###   ########.fr       */
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
		return (ft_putnbr_base((long)va_arg(lst, int), BASE_10, 10));
	return (0);
}

int	ft_printf(const char *input, ...)
{
    int	i;
	int	len;
	va_list lst;
	
	va_start(lst, input);
	i = 0;
	len  = 0;
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




/*


	else if (c == 'u')
		return (ft_putstr(
				ft_convert(va_arg(lst, unsigned int), "0123456789")));
	else if (c == 'x')
		return (ft_putstr(
				ft_convert(va_arg(lst, unsigned int), "0123456789abcdef")));
	else if (c == 'X')
		return (ft_putstr(
			ft_convert(va_arg(lst, unsigned int), "0123456789ABCDEF")));
	else if (c == '%')
		return (write(1, "%%", 1));
	*/	

/*

	if (*input == 'c')
		return (ft_is_char(va_arg(arr, int)));
	else if (*input == 's')
		return (ft_is_string(va_arg(arr, char *)));
	else if (*input == 'x' || *input == 'X')
		return (ft_is_hex(va_arg(arr, unsigned int), *input));
	else if (*input == 'p')
		return (ft_is_address(va_arg(arr, unsigned long)));
	else if (*input == 'd' || *input == 'i')
		return (ft_is_int(va_arg(arr, int)));
	else if (*input == 'u')
		return (ft_is_unsigned(va_arg(arr, unsigned int)));

	else
		return (-1);
		*/