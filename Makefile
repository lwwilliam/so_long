# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:38:00 by lwilliam          #+#    #+#              #
#    Updated: 2022/08/04 19:55:57 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJ = so_long.c char_ani.c keybuttons.c enemy.c wall.c char_coord.c wasd_move.c map_handle.c ./gnl/*.c

CC = gcc 

FLAGS = -Wall -Wextra -Werror

# %.o: %.c
# 	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) fclean
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)  #-fsanitize=address -g3
	./so_long

all : $(NAME)

clean : 
	rm -rf *.dSYM

fclean :
	rm -f so_long
	
re: fclean all