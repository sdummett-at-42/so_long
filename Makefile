# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:50:30 by sdummett          #+#    #+#              #
#    Updated: 2021/07/21 00:15:18 by sdummett         ###   ########.fr        #
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
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			map_parser/map_parser.c \
			map_parser/map_parser_2.c \
			map_parser/map_parser_3.c \
			map_parser/map_parser_4.c \
			map_parser/map_parser_5.c \
			key_hooks/key_hooks.c \
			key_hooks/key_hooks_2.c \
			inits/init_funcs.c \
			inits/map_init.c \
			inits/map_init_sprites.c \
			inits/map_init_sprites_2.c \
			inits/init_all_vars.c \
			inits/imgs_init.c \
			inits/imgs_init_2.c \
			inits/imgs_init_3.c \
			inits/imgs_init_4.c \
			inits/collectible_img.c \
			animations/player_mov.c \
			animations/animated_collectibles.c \
			animations/tobi_tp_animation.c \
			animations/madara_atk_animation.c \
			animations/lost_animation.c \
			animations/win_animation.c \
			animations/move_right.c \
			animations/move_left.c \
			animations/move_up_left.c \
			animations/move_up_right.c \
			animations/move_down_left.c \
			animations/move_down_right.c \
			utils/utils.c \
			utils/utils_2.c \
			utils/free_funcs.c \
			utils/ft_itoa.c 

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

bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make clean -C minilibx-linux

re: fclean all