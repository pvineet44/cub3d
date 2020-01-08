# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vparekh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/06 13:01:20 by vparekh           #+#    #+#              #
#*   Updated: 2020/01/06 13:01:21 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY: all, ,clean, re, fclean

NAME = cub3d.a

SRC = get_next_line_utils.c\
		get_next_line.c\
		gen_utils.c\
		cub3d_main.c\
		parse_utils.c\
		cub3d_engine.c\
		struct_utils.c\
		cub3d_movements.c\

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib	$(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all