# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:38:00 by lwilliam          #+#    #+#              #
#    Updated: 2022/07/22 14:00:53 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJ = main.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

# %.o: %.c
# 	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) fclean
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	./so_long

all : $(NAME)

clean : 
	rm -f

fclean :
	rm -f so_long
	
re: fclean all