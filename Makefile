# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:38:00 by lwilliam          #+#    #+#              #
#    Updated: 2022/08/13 22:04:50 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJ = so_long.c char_ani.c keybuttons.c \
		wall.c enemy.c char_coord.c wasd_move.c map_handle.c \
		ft_putnbr.c ft_strtrim.c ft_bzero.c coin.c exit.c \
		error_arg.c map_error.c ./gnl/*.c
		
CC = gcc 

FLAGS = -Wall -Wextra -Werror

# %.o: %.c
# 	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) fclean
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) #-fsanitize=address -g3

all : $(NAME)

clean : 
	rm -rf *.dSYM

fclean :
	rm -f so_long
	
re: fclean all