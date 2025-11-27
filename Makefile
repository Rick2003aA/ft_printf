# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 16:11:19 by rtsubuku          #+#    #+#              #
#    Updated: 2025/11/12 11:56:48 by rtsubuku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c print_any.c print_any2.c puts.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	=  -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= rcs
RM		= rm -f
DEPS	= ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all