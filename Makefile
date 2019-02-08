# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:12:42 by lgaultie          #+#    #+#              #
#    Updated: 2019/02/07 20:06:16 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = @clang
CFLAGS = -Wall -Werror -Wextra 
OBJDIR = src
SRCS =	main.c				\
		read_and_check.c	\
		parsing.c			\
		free.c				\
		map.c				\
		solve.c				\
		misc.c

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

_GREEN=\e[32m
_YELLOW=\e[33m
_BLUE=\e[34m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)

	@printf "Compiling ...:"
	@cd libft && make
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@printf "[$(_GREEN)✓$(_END)]\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "Clean     ...:"
	@cd libft && make clean
	@rm -f $(OBJ)
	@printf "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@printf "fclean    ...:"
	@cd libft && rm -f libft.a
	@rm -f $(OBJ)$(NAME)
	@printf "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
