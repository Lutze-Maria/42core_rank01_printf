/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:55:50 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 13:14:09 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	unsigned char	ch;
	int				bytes_written;

	ch = (unsigned char)c;
	bytes_written = write(1, &c, 1);
	if (bytes_written == -1)
		return (-1);
	else
		return (bytes_written);
}

int	ft_putstr(char *s)
{
	int	bytes_written;
	int	i;

	bytes_written = 0;
	if (!s)
	{
		bytes_written = write(1, "(null)", 6);
		return (bytes_written);
	}
	i = 0;
	while (s[i])
	{
		bytes_written += write(1, &s[i], 1);
		i++;
	}
	return (bytes_written);
}
