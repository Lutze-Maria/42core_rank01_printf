/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:12:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/05/01 18:17:19 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_get_hexsize(unsigned int n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n != 0)
    {
        n /= 16;
        len++;
    }
    return (len);
}

int handle_hex(unsigned int num, int is_upper)
{
    char    *base;
    char    *s;
    int     str_len;

    if (is_upper == 0)
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    str_len = ft_get_hexsize(num);
    s = malloc(sizeof(char) * (str_len + 1));
    if (!s)
        return (0);
    s[str_len] = '\0';
    if (num == 0)
        s[0] = '0';
    while (num != 0)
    {
        s[--str_len] = base[num % 16];
        num /= 16;
    }
    ft_putstr_fd(s, 1);
    free(s);
    return (str_len);
}

static int  ft_get_ptrsize(unsigned long n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n != 0)
    {
        n /= 16;
        len++;
    }
    return (len);
}

// %p The void * pointer argument has to be printed in hexadecimal format. 
// For %p: Print 0x first, 
//         then pass the pointer (as an unsigned long) to the lowercase hex logic.
int handle_pointer(void *ptr)
{
    unsigned long   num;
    char            *base;
    char            *s;
    int             str_len;

    num = (unsigned long)ptr;
    base = "0123456789abcdef";

    if (!ptr)
    {
    ft_putstr_fd("(nil)", 1);
    return (5);
    }
    ft_putstr_fd("0x", 1);
    str_len = ft_get_ptrsize(num);
    s = malloc(sizeof(char) * (str_len + 1));
    if (!s)
        return (2);
    s[str_len] = '\0';
    if (num == 0)
        s[0] = '0';
    while (num != 0)
    {
        s[--str_len] = base[num % 16];
        num /= 16;
    }
    ft_putstr_fd(s, 1);
    free(s);
    return (str_len + 2);
}
