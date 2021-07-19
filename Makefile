# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:50:30 by sdummett          #+#    #+#              #
#    Updated: 2021/07/19 23:36:53 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC		= clang
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= so_long
SRC		= so_long.c \
			utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			map_parser.c \
			init_funcs.c \
			map_init.c \
			collectible_img.c \
			player_img.c \
			player_mov.c \
			animated_collectibles.c \
			key_hooks.c \
			ft_itoa.c \
			init_all_vars.c \
			free_funcs.c \
			debugging_funcs.c
OBJ		= $(SRC:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx-linux
	$(CC) $(OBJ) -o $(NAME) -lXext -lX11 -lm minilibx-linux/libmlx_Linux.a

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1000 -o $@ $<

#bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make clean -C minilibx-linux

re: fclean all