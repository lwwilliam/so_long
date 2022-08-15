# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:38:00 by lwilliam          #+#    #+#              #
#    Updated: 2022/08/15 20:56:15 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c char_ani.c keybuttons.c \
		wall.c enemy.c char_coord.c wasd_move.c map_handle.c \
		ft_putnbr.c ft_strtrim.c ft_bzero.c coin.c exit.c \
		error_arg.c map_error.c put_str.c ft_itoa.c \
		./gnl/get_next_line_utils.c ./gnl/get_next_line.c
		
CC = gcc 

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -f *.o ./gnl/*.o

fclean : clean
	rm -f so_long
	
re: fclean all

.PHONY : $(NAME)