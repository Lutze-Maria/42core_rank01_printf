/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/05/01 18:17:19 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_char(int c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int handle_string(char *s)
{
    int str_len;

    if (!s)
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    str_len = ft_strlen(s);
    ft_putstr_fd(s, 1);
    return (str_len);
}
