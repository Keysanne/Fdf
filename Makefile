# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 14:49:02 by tbatteux          #+#    #+#              #
#    Updated: 2023/05/26 18:58:50 by tbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf
RESSOURCES= ./minilibx-linux

all: ${NAME}

${NAME}:
	gcc -o fdf *.c -L ${RESSOURCES} -lm -lmlx -lXext -lX11 -I ${RESSOURCES}

clean:
	rm -f fdf

fclean: clean

re: fclean all
