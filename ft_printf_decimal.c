/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 13:58:16 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long numb)
{
	int	counter;

	counter = 0;
	if (numb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		counter++;
		numb = -numb;
	}
	if (numb > 9)
		counter += ft_putnbr(numb / 10);
	counter += ft_putchar((numb % 10) + '0');
	return (counter);
}
