/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:13:38 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/07 11:17:50 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	num;
	int				str_len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	num = (unsigned long)ptr;
	ft_putstr("0x");
	str_len = 0;
	str_len = ft_puthex(num, "0123456789abcdef");
	return (str_len + 2);
}
