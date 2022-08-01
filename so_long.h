/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:03:20 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/01 12:52:42 by lwilliam         ###   ########.fr       */
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
# define FRAME 5

typedef struct s_vars {
	void	*img;
	void	*img2;
	void	*mlx;
	void	*win;
	char	*addr;
	char	*xpm_path;
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
}				t_vars;

int	animation(t_vars *vars);
int	character(t_vars *vars);
int	map(t_vars *vars);
int	exit_button(t_vars *vars);
int	win_init(t_vars *vars);
int	keybutton(int keycode, t_vars *vars);

#endif