/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 13:25:21 by lschawer         ###   ########.fr       */
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
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	if (specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
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
		if (*format == '%' && (format + 1))
		{
			check = ft_handle_specifier(*(format + 1), &args);
			if (check == -1)
				return (va_end(args), -1);
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

int main(void)
{
	int ft_ret;
	int std_ret;

	printf("=== STARTING FT_PRINTF TESTS ===\n\n");

	// 1. Character (%c) and Percent (%%)
	printf("--- Test 1: %%c and %%%%\n");
	ft_ret = ft_printf("Mine: %c | %%\n", 'A');
	write (1, "------------------\n", 19);
	std_ret = printf("Std : %c | %%\n", 'A');
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	// 2. String (%s)
	printf("--- Test 2: %%s (Standard and Empty)\n");
	ft_ret = ft_printf("Mine: %s | %s\n", "Hello, 42!", "");
	write (1, "------------------\n", 19);
	std_ret = printf("Std : %s | %s\n", "Hello, 42!", "");
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	printf("--- Test 2b: %%s (NULL Pointer)\n");
	ft_ret = ft_printf("Mine: %s\n", (char *)NULL);
	std_ret = printf("Std : %s\n", (char *)NULL);
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	// 3. Integers (%d and %i)
	printf("--- Test 3: %%d and %%i (Positive, Negative, Zero)\n");
	ft_ret = ft_printf("Mine: %d | %i | %d\n", 42, -2147483647, 0);
	write (1, "------------------\n", 19);
	std_ret = printf("Std : %d | %i | %d\n", 42, -2147483647, 0);
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	// 4. Unsigned Decimals (%u)
	printf("--- Test 4: %%u (Standard and Max Unsigned Int)\n");
	ft_ret = ft_printf("Mine: %u | %u\n", 12345, 4294967295U);
	write (1, "------------------\n", 19);
	std_ret = printf("Std : %u | %u\n", 12345, 4294967295U);
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	// 5. Hexadecimal (%x and %X)
	printf("--- Test 5: %%x and %%X\n");
	ft_ret = ft_printf("Mine: %x | %X | %x\n", 255, 3735928559U, 0);
	write (1, "------------------\n", 19);
	std_ret = printf("Std : %x | %X | %x\n", 255, 3735928559U, 0);
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	// 6. Pointer (%p)
	printf("--- Test 6: %%p (Valid Address and NULL)\n");
	int num = 42;
	ft_ret = ft_printf("Mine: %p | %p\n", &num, NULL);
	write (1, "------------------\n", 19);
	std_ret = printf("Std : %p | %p\n", &num, NULL);
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	// 7. Mixed Multi-argument String
	printf("--- Test 7: Mixed Arguments\n");
	ft_ret = ft_printf("Mine: Score: %d, Grade: %c, Hex: %x, 
		User: %s\n", 95, 'A', 95, "Cadet");
	write (1, "------------------\n", 19);
	std_ret = printf("Std : Score: %d, Grade: %c, Hex: %x, 
		User: %s\n", 95, 'A', 95, "Cadet");
	printf("Return Value -> Mine: %d | Std: %d\n\n", ft_ret, std_ret);

	printf("=== TESTS COMPLETE ===\n");
	return (0);
}
  */