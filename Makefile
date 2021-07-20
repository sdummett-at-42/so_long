# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:50:30 by sdummett          #+#    #+#              #
#    Updated: 2021/07/20 05:34:32 by sdummett         ###   ########.fr        #
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
			utils_2.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			map_parser.c \
			map_parser_2.c \
			map_parser_3.c \
			map_parser_4.c \
			map_parser_5.c \
			init_funcs.c \
			map_init.c \
			map_init_sprites.c \
			map_init_sprites_2.c \
			collectible_img.c \
			player_mov.c \
			animated_collectibles.c \
			key_hooks.c \
			key_hooks_2.c \
			ft_itoa.c \
			init_all_vars.c \
			imgs_init.c \
			imgs_init_2.c \
			imgs_init_3.c \
			imgs_init_4.c \
			free_funcs.c \
			tobi_tp_animation.c \
			madara_atk_animation.c \
			lost_animation.c \
			win_animation.c \
			move_right.c \
			move_left.c \
			move_up_left.c \
			move_up_right.c \
			move_down_left.c \
			move_down_right.c

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