/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:03:20 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 14:50:22 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"

# define MAP "./xpm/grass.xpm"
# define CLOSE "./xpm/close.xpm"
# define OPEN1 "./xpm/open1.xpm"
# define OPEN2 "./xpm/open2.xpm"
# define OPEN3 "./xpm/open3.xpm"
# define OPEN4 "./xpm/open4.xpm"
# define OPEN5 "./xpm/open5.xpm"
# define OPEN6 "./xpm/open6.xpm"
# define OPEN7 "./xpm/open7.xpm"
# define OPEN8 "./xpm/open8.xpm"
# define GHOST1 "./xpm/g1.xpm"
# define GHOST2 "./xpm/g2.xpm"
# define COIN1 "./xpm/coin1.xpm"
# define COIN2 "./xpm/coin2.xpm"
# define WALL "./xpm/wall.xpm"
# define EXIT "./xpm/exit.xpm"
# define FRAME 10

// typedef struct s_xpm {
// 	void	*close;
// 	void	*open1;
// 	void	*open2;
// 	void	*open3;
// 	void	*open4;
// 	void	*open5;
// 	void	*open6;
// 	void	*open7;
// 	void	*open8;
// }				t_xpm;

typedef struct s_vars
{
	void	*img;
	void	*img2;
	void	*enemy_img;
	void	*coin_img;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*addr;
	char	*xpm_path;
	char	*enemy_path;
	char	*coin_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		a;
	int		b;
	int		kkk;
	int		w_x;
	int		w_y;
	int		p2_x;
	int		p2_y;
	int		c_x;
	int		c_y;
	int		e_x;
	int		e_y;
	int		pixel_w;
	int		pixel_h;
	int		coin_collected;
	int		coin;

	int		map_w;
	int		map_h;
	char	*line;
	char	*map;
	int		pos_x;
	int		pos_y;
	char	*dup;
	char	*str;
	int		str_pos;
	int		n_of_m;
	char	*map_name;
	int		for_werror;
}	t_vars;

int		animation(t_vars *vars);
int		character(t_vars *vars);
int		wasd_animation(t_vars *vars);
int		map(t_vars *vars);
int		exit_button(t_vars *vars);
int		win_init(t_vars *vars);
int		keybutton(int keycode, t_vars *vars);
int		key_read(int key, t_vars *vars);
int		enemy(t_vars *vars);
int		enemy_placement(t_vars *vars);
int		wall_placement(t_vars *vars);
int		wall_coords(t_vars *vars);
int		coin(t_vars *vars);
int		coin_placement(t_vars *vars);

void	up_funct(t_vars *vars);
void	down_funct(t_vars *vars);
void	left_funct(t_vars *vars);
void	right_funct(t_vars *vars);
int		w_animation(t_vars *vars);
int		a_animation(t_vars *vars);
int		s_animation(t_vars *vars);
int		d_animation(t_vars *vars);
void	meth(t_vars *vars);

char	*ft_strtrim(char const *s1, char const *set);
int		resres(int e, int f);
void	map_read(t_vars *vars);
int		map_size(t_vars *vars);
int		map_height(t_vars *vars);
void	array(t_vars *vars);
void	ft_bzero(void *s, size_t n);
void	item_pos(t_vars *vars);
void	pos_formula(t_vars *vars);
void	coin_take(t_vars *vars);
void	duptostr(t_vars *vars);
void	ft_putnbr(int nb);
void	e_filter(t_vars *vars, int x);
int		exit_placement(t_vars *vars);
void	ft_putchar(char c);
void	arguments(t_vars *vars, char **av, int ac);
void	error_exit(t_vars *vars);
void	map_error(t_vars *vars);
void	map_error2(t_vars *vars);
void	map_error3(t_vars *vars);
void	map_error4(int play, int end);
char	*ft_itoa(int n);
void	num_move(t_vars *vars);
// void	xpm_init(t_vars *vars);
// void	print_test(t_vars *vars);

#endif