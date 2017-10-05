# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 18:26:07 by pnizet            #+#    #+#              #
#    Updated: 2017/10/04 19:26:57 by pnizet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	map.c \
	reader.c \
	solver.c \
	tetrimino.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
INC = ./include/

LIBFT = ./libft/libft.a
FTINC = -I ./libft/
FTLINK = -L ./libft? -libf

OBJDIR = ./obj/
SRCDIR = ./src/
INCDIR = ./includes/

.PHONY: all clean fclean re

all: obj libft$(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
		gcc $(CFLAGS) $(FTINC) -I $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FTLINK) -o $(NAME)

libft: $(LIBFT)

$(LIBFT):
		make -C ./libft/

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
