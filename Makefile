# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:12:42 by lgaultie          #+#    #+#              #
#    Updated: 2019/02/14 12:31:23 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = @clang
CFLAGS = -Wall -Werror -Wextra 
OBJDIR = obj
SRCDIR = src
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
	@printf "compiling... "
	@cd libft && make
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@printf "[$(_GREEN)✓$(_END)]\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... "
	@cd libft && make clean
	@rm -rf $(OBJDIR)
	@printf "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@printf "fclean... "
	@cd libft && rm -f libft.a
	@rm -f $(NAME)
	@printf "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
