# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 12:57:38 by nmostert          #+#    #+#              #
#    Updated: 2018/09/26 09:08:01 by nmostert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = lem-in

CFLAGS = -Wall -Werror -Wextra
CC = gcc $(CFLAGS)

LFLAGS = -L ./libft/
LFT = -lft

SRC_P = ./helpers/
OBJ_P = ./objs/
INC = ./includes/

CFILES = room_adding.c \
ant_counter.c \
make_edge_table.c \
leaveandfree.c \
free_array.c \
joiner.c \
links.c \
print_matrix.c \
print_result.c \
room_index.c \
rooms.c \
algo.c \

OBJ_N = $(CFILES:%.c=%.o)

SRC = $(addprefix $(SRC_P)/,$(SRC_N))
OBJ = $(addprefix $(OBJ_P)/,$(OBJ_N))

all: $(NAME1)

$(NAME1): $(OBJ) $(INC) ./mains/main.c
	@make -C./libft/
	@$(CC) -o $@  $(OBJ) ./mains/main.c  $(LFLAGS) $(LFT)


$(OBJ_P)%.o: $(SRC_P)%.c
	@mkdir $(OBJ_P) 2> /dev/null || true
	@$(CC) -I$(INC) -o $@ -c $<

clean: cleanlib
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_P) 2> /dev/null || true

cleanlib:
	@make clean -C ./libft/

fclean: clean fcleanlib
	@rm -f $(NAME1)

fcleanlib:
	@make fclean -C ./libft/

re : fclean all

.PHONY: clean fclean re
