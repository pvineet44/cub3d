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

SRC = srcs/struct_utils.c\
srcs/parse_utils.c\
srcs/get_next_line_utils.c\
srcs/get_next_line.c\
srcs/gen_utils.c\
srcs/cub3d_movements.c\
srcs/cub3d_math.c\
srcs/cub3d_main.c\
srcs/cub3d_events.c\
srcs/window.c\
srcs/cub3d_pixel.c\
srcs/cub3d_textures.c\
srcs/cub3d_rays.c\
srcs/cub3d_game.c\

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