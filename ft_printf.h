/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:15:12 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/04 09:42:54 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

// main logic function
int	        ft_printf(const char *, ...);

// utility functions
int         handle_char(int c);
int         handle_string(char *s);
int         handle_int(int i);
int         handle_unsign(unsigned int u);
int         handle_hex(unsigned int hex, int is_upper);
int         handle_pointer(void *ptr);

#endif
