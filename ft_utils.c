/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:11:41 by ekart             #+#    #+#             */
/*   Updated: 2025/08/03 12:13:22 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		ft_putchar(str[len++]);
	return (len);
}

int	ft_putnbr_dec(long num, char *base, unsigned long base_len)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += ft_putchar('-');
		num = -num;
	}
	if (num >= base_len)
		len += ft_putnbr_base(num / base_len, base, base_len);
	len += write(1, &base[num % base_len], 1);
	return (len);
}
int	ft_putnbr_base_u(unsigned long num, char *base, unsigned long base_len)
{
	int	len;

	len = 0;
	if (num >= base_len)
		len += ft_putnbr_base_u(num / base_len, base, base_len);
	len += write(1, &base[num % base_len], 1);
	return (len);
}
int	ft_putnbr_base(unsigned long num, char *base, unsigned long base_len)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += ft_putchar('-');
		num = -num;
	}
	if ((unsigned long)num >= base_len)
		len += ft_putnbr_base(num / base_len, base, base_len);
	len += write(1, &base[num % base_len], 1);
	return (len);
}

int	ft_putpointer(void *ptr)
{
	int				len;
	unsigned long	address;

	address = (unsigned long)ptr;
	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_putnbr_base(address, LOWER_BASE, 16);
	return (len);
}
