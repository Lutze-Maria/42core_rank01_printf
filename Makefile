# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/01 18:13:34 by lschawer          #+#    #+#              #
#    Updated: 2026/06/05 13:07:50 by lschawer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# 1. Variables
NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# 2. Source Files
SRCS        = ft_printf.c ft_printf_hex.c ft_printf_ptr.c\
				ft_printf_decimal.c ft_printf_conversions.c

# 3. Object Files
OBJS        = $(SRCS:.c=.o)

# 4. Mandatory Rules
all: $(NAME)

# i. compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ii. Create libftprintf.a directly from your object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# 5. Phony Targets
# This prevents make from confusing these rules with files of the same name
.PHONY: all clean fclean re
