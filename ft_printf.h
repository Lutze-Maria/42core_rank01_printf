/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:15:12 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 13:13:03 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// main logic function
int	ft_printf(const char *format, ...);
int	ft_handle_specifier(char specifier, va_list *args);

// utility functions
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long long i);
int	ft_puthex(unsigned long hex, char *base);
int	ft_putptr(void *ptr);

// edge cases
int	is_specifier(char c);
int	parse_conversion(const char *fmt, va_list *args, int *consumed);

#endif