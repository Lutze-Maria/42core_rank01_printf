/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/07 11:28:45 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_specifier(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (specifier == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum;
	int		check;

	sum = 0;
	check = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			check = ft_handle_specifier(*(format + 1), &args);
			if (check == -1)
				check = ft_putchar('%');
			sum += check;
			format += 2;
		}
		else
		{
			sum += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (sum);
}
/* 
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	ft_printf("one %t three %s 1 %i 3\n", "two", 2);
	   printf("one %t three %s 1 %i 3\n\n\n", "two", 2);


	ft_printf("%c\n", 0);
	ft_printf("%c%c%c\n", 'A', 'B', 'C');

	printf("=== CHAR ===\n");
	ret1 = printf("printf    : %c\n", 'A');
	ret2 = ft_printf("ft_printf : %c\n", 'A');
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== STRING ===\n");
	ret1 = printf("printf    : %s\n", "Hello");
	ret2 = ft_printf("ft_printf : %s\n", "Hello");
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== POINTER ===\n");
	int x = 42;
	ret1 = printf("printf    : %p\n", &x);
	ret2 = ft_printf("ft_printf : %p\n", &x);
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== DECIMAL ===\n");
	ret1 = printf("printf    : %d\n", -42);
	ret2 = ft_printf("ft_printf : %d\n", -42);
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== INTEGER ===\n");
	ret1 = printf("printf    : %i\n", 12345);
	ret2 = ft_printf("ft_printf : %i\n", 12345);
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== UNSIGNED ===\n");
	ret1 = printf("printf    : %u\n", 4294967295U);
	ret2 = ft_printf("ft_printf : %u\n", 4294967295U);
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== HEX LOWER ===\n");
	ret1 = printf("printf    : %x\n", 255);
	ret2 = ft_printf("ft_printf : %x\n", 255);
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== HEX UPPER ===\n");
	ret1 = printf("printf    : %X\n", 255);
	ret2 = ft_printf("ft_printf : %X\n", 255);
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	printf("=== PERCENT ===\n");
	ret1 = printf("printf    : %%\n");
	ret2 = ft_printf("ft_printf : %%\n");
	printf("ret printf=%d | ret ft_printf=%d\n\n", ret1, ret2);

	return (0);
}
 */