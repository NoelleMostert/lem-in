# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 08:56:15 by nmostert          #+#    #+#              #
#    Updated: 2018/09/25 12:17:52 by nmostert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC_PATH=./includes/
LIB_SRC_PATH =./libft_src/
OBJ_PATH=./objs/

FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)

OBJ= $(wildcard ./objs/*.o)

all: $(NAME)

$(NAME): SUBDIR
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	find . -name "*.h.gch" -delete

SUBDIR:
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@make -C $(LIB_SRC_PATH)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
