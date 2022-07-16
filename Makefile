# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 06:09:26 by gchernys          #+#    #+#              #
#    Updated: 2022/07/14 17:27:27 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

FLAGS = -crs

mlx = ./mlx/libmlx.a

FILES = ./src/check_valid.c		\
		./src/check_more_valid.c	\
		./src/freeing.c			\
		./src/get_map.c			\
		./src/InitData.c			\
		./main_so_long.c		\
		./src/movement.c			\
		./src/put_image.c
		
OBJECTS = $(FILES:.c=.o)

LIBFT = cd libft && make

LIB = libft/libft.a

$(NAME)	:
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(FILES) $(LIB) $(mlx) -framework OpenGL -framework AppKit

all : $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all
