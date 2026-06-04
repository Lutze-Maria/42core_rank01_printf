/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/04 09:41:08 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_handle_specifier(char specifier, va_list args)
{
    int count;

    count = 0;
    if (specifier == '%')
    {
        ft_putchar_fd('%', 1);
        count += 1;
    }
    else if (specifier == 'c')
        count += handle_char(va_arg(args, int));
    else if (specifier == 's')
        count += handle_string(va_arg(args, char *));
    else if (specifier == 'd' || specifier == 'i')
        count += handle_int(va_arg(args, int));
    else if (specifier == 'u')
        count += handle_unsign(va_arg(args, unsigned int));
    else if (specifier == 'x')
        count += handle_hex(va_arg(args, unsigned int), 0);
    else if (specifier == 'X')
        count += handle_hex(va_arg(args, unsigned int), 1);
    else if (specifier == 'p')
        count += handle_pointer(va_arg(args, void *));
    return (count);
    //TODO Write can fail with -1.
    // if not valid specifier -1
}

int	ft_printf(const char *format, ...)
{
    va_list args;
    int     sum;
    int     i;

    i = 0;
    sum = 0;
    if (!format)
        return (-1);
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format [i + 1])
        {
            sum += ft_handle_specifier(format[i + 1], &args);    // TODO unbedingt als pointer übergeben
            i++;
            //return (va_end(args), 1);
        }
        else
        {
            sum += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return (sum);
}
