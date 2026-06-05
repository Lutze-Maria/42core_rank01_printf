/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 13:54:24 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, int is_upper)
{
	char	buffer[17];
	char	*base;
	int		i;
	int		count;

	if (is_upper == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 16;
	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	else
	{
		while (num != 0)
		{
			buffer[--i] = base[num % 16];
			num /= 16;
		}
	}
	ft_putstr(&buffer[i]);
	count = 16 - i;
	return (count);
}
