/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/08 11:17:21 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_specifier(char specifier, va_list *args)
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

int	is_specifier(char c)
{
	return (c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == '%');
}

int	parse_conversion(const char *fmt, va_list *args, int *consumed)
{
	int	i;

	i = 1;
	while (fmt[i] == ' ')
		i++;
	*consumed = i;
	if (is_specifier(fmt[i]))
		return (ft_handle_specifier(fmt[i], args));
	return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum;
	int		written;
	int		consumed;

	sum = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			written = parse_conversion(format, &args, &consumed);
			if (written == -1)
				return (-1);
			format += consumed + 1;
		}
		else
			written = write(1, format++, 1);
		if (written == -1)
			return (-1);
		sum += written;
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

	ret1 = printf("a %t c d\n", 'b');
	ret2 = ft_printf("a %t c d\n", 'b');
	printf("ret printf=%d | ret ft_printf=%d\n\n\n", ret1, ret2);

	ret1 = printf("a %    c c d\n", 'b');
	ret2 = ft_printf("a %    c c d\n", 'b');
	printf("ret printf=%d | ret ft_printf=%d\n\n\n", ret1, ret2);

	ret1 = printf("a % \n", 'b');
	ret2 = ft_printf("a % \n", 'b');
	printf("ret printf=%d | ret ft_printf=%d\n\n\n", ret1, ret2);


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