# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoussei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 13:10:05 by ahoussei          #+#    #+#              #
#    Updated: 2018/07/02 13:10:06 by ahoussei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAG = -Wall -Wextra -Werror -g -fsanitize=address -o

LIBFT = libft/

COMP = make -C $(LIBFT) re

COMPC = make -C $(LIBFT) clean

COMPF = make -C $(LIBFT) fclean

NAME = get_next_line

SRCS = $(LIBFT)libft.a \
		get_next_line.c \
		main.c \

all:	$(NAME)

$(NAME):
		@$(COMP)
		@$(CC) $(FLAG) $(NAME) $(SRCS)

clean:
		@$(COMPC)

fclean:
		@$(COMPF)
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re