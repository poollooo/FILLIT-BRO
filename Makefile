# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnizet <pnizet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 18:26:07 by pnizet            #+#    #+#              #
#    Updated: 2017/10/26 15:27:24 by pnizet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

FILES += 	sources/algoo_tool.c \
					sources/algoo_tool_2.0.c \
					sources/check_all.c \
					sources/coordinates.c \
					sources/main.c \
					sources/solver.c \
					sources/libft.c \
					sources/libft_2.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(FILES)
	gcc -o $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf fillit

re: fclean all
