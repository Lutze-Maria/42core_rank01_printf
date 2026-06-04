/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/05/01 18:17:19 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int handle_int(int numb)
{
    char    *s;
    int     str_len;
    
    s = ft_itoa(numb);
    if (!s)
        return (0);
    str_len = ft_strlen(s);
    ft_putstr_fd(s, 1);
    free (s);
    return (str_len);
}

static void	ft_fillstr(char *s, unsigned int n, int len)
{
	while (n != 0)
	{
		s[len--] = (n % 10) + '0';
		n = n / 10;
	}
}

static int	ft_get_intsize(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*s;

	len = ft_get_intsize(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	ft_fillstr(s, n, (len - 1));
	return (s);
}

int handle_unsign(unsigned int numb)
{
    char    *s;
    int     str_len;
    
    s = ft_utoa(numb);
    if (!s)
        return (0);
    str_len = ft_strlen(s);
    ft_putstr_fd(s, 1);
    free (s);
    return (str_len);
}