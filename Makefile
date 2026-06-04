# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/01 18:13:34 by lschawer          #+#    #+#              #
#    Updated: 2026/05/01 18:14:16 by lschawer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# 1. Variables
NAME        = ft_printf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# Relative paths to navigate folder structure
LIBFT_DIR   = ../../rank00/libft
LIBFT       = $(LIBFT_DIR)/libft.a

# tells the compiler where to look for libft.h
INCLUDES    = -I. -I$(LIBFT_DIR)

# 2. Source Files
SRCS        = ft_printf.c ft_printf_hex.c \
				ft_printf_decimal.c ft_printf_conversions.c

# 3. Object Files
OBJS        = $(SRCS:.c=.o)

# 4. Mandatory Rules
all: $(NAME)

# i. First, build libft.a if it doesn't exist or has changed
$(LIBFT):
	@make -C $(LIBFT_DIR)

# ii. then compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# iii. Combine objects with libft.a into ft_printf.a
$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	r$(RM) $(NAME)

re: fclean all

# 5. Phony Targets
# This prevents make from confusing these rules with files of the same name
.PHONY: all clean fclean re
