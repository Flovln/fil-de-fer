# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fviolin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/23 10:13:51 by fviolin           #+#    #+#              #
#    Updated: 2016/03/30 12:05:01 by fviolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c \
	srcs/save_map.c \
	srcs/error_handling.c \
	srcs/init_struct_env.c \
	srcs/draw_map.c \
	srcs/events.c \
	srcs/projections.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -I../../minilibx_macos
INCLUDES = -I../../minilibx_macos
LIBS = -L../libft -lft -L../../minilibx_macos -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	make -C ../libft
	gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)
	make -C ../libft/ clean

fclean: clean
	rm -rf $(NAME)
	make fclean -C ../libft

re: fclean all

.PHONY : all clean fclean re
