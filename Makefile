# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:50:30 by sdummett          #+#    #+#              #
#    Updated: 2021/07/14 22:07:11 by sdummett         ###   ########.fr        #
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
			gnl/get_next_line_utils.c
OBJ		= $(SRC:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)  -lXext -lX11 -lm  minilibx-linux/libmlx_Linux.a
#$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1000 -o $@ $<

#bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all