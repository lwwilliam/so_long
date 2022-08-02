/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:03:20 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/02 12:08:12 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

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
# define WALL "./xpm/wall.xpm"
# define FRAME 3

typedef struct s_vars {
	void	*img;
	void	*img2;
	void	*enemy_img;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*addr;
	char	*xpm_path;
	char	*enemy_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		a;
	int		b;
	int		kkk;
	int		w_x;
	int		w_y;
}				t_vars;

int	animation(t_vars *vars);
int	character(t_vars *vars);
int	wasd_animation(t_vars *vars);
int	map(t_vars *vars);
int	exit_button(t_vars *vars);
int	win_init(t_vars *vars);
int	keybutton(int keycode, t_vars *vars);
int	key_read(int key, t_vars *vars);
int	enemy(t_vars *vars);
int	enemy_placement(t_vars *vars);
int	wall_placement(t_vars *vars);
int	wall_coords(t_vars *vars);

#endif