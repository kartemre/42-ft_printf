/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:29:39 by ekart             #+#    #+#             */
/*   Updated: 2025/08/03 12:03:14 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UPPER_BASE "0123456789ABCDEF"
# define LOWER_BASE "0123456789abcdef"
# define BASE_10 "0123456789"

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned long num, char *base, unsigned long base_len);
int	ft_putpointer(void *ptr);
int	ft_putnbr_dec(long num, char *base, unsigned long base_len);
int	ft_putnbr_base_u(unsigned long num, char *base, unsigned long base_len);

#endif
