/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:03:20 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/04 21:07:59 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
# define FRAME 8
# define BUFFER_SIZE 10000

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
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		a;
	int		b;
	int		kkk;
	int		w_x;
	int		w_y;
	int		pixel_w;
	int		pixel_h;

	int		map_w;
	int		map_h;

}				t_vars;

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

void	up_funct(t_vars *vars);
void	down_funct(t_vars *vars);
void	left_funct(t_vars *vars);
void	right_funct(t_vars *vars);

void	map_read(t_vars *vars);
int		map_size(t_vars *vars);
int		map_height(t_vars *vars);
void	play_pos(t_vars *vars);
// void	xpm_init(t_vars *vars);

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *str, int y);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		read_funct(int fd, char **buffer, int *x);

#endif