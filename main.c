/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:53:52 by ekart             #+#    #+#             */
/*   Updated: 2025/08/03 10:40:41 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
    int d = -2147483649;
    ft_printf("Character: %d\n", d);
    printf("Character: %d\n", d);

    /*
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Integer: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Percent sign: %%\n");
    */
    return 0;
}