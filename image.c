/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/01 11:00:12 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAP "./xpm/grass.xpm"
#define CLOSE "./xpm/close.xpm"
#define OPEN1 "./xpm/open1.xpm"
#define OPEN2 "./xpm/open2.xpm"
#define FRAME 5

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
}				t_vars;

int	animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame == FRAME)
		vars->xpm_path = CLOSE;
	if (frame >= FRAME * 2)
		vars->xpm_path = OPEN1;
	if (frame >= FRAME * 3)
	{
		vars->xpm_path = OPEN2;
		frame = 0;
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->xpm_path,
			&vars->img_width, &vars->img_height);
	return (0);
}

int	character(t_vars *vars)
{
	vars->a = 0;
	vars->b = 0;
	animation(vars);
	while (vars->b != 1024)
	{
		vars->a = 0;
		while (vars->a != 1920)
		{
			if (vars->a == vars->x && vars->b == vars->y)
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
					vars->a, vars->b);
			}
			vars->a += 64;
		}
		vars->b += 64;
	}
	return (0);
}

int	map(t_vars *vars)
{
	vars->b = 0;
	while (vars->b != 1024)
	{
		vars->a = 0;
		while (vars->a != 1920)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				vars->a, vars->b);
			vars->a += 64;
		}
		vars->b += 64;
	}
	character(vars);
	return (0);
}

int	exit_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	write(0, "Exit\n", 5);
	exit(0);
}

int	keybutton(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_button(vars);
	if (keycode == 2)
		if (vars->x < 1856)
			vars->x += 64;
	if (keycode == 0)
		if (vars->x > 0)
			vars->x -= 64;
	if (keycode == 1)
		if (vars->y < 960)
			vars->y += 64;
	if (keycode == 13)
		if (vars->y > 0)
			vars->y -= 64;
	return (0);
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	vars->x = 0;
	vars->y = 0;
	return(0);
}

int	main(void)
{
	t_vars	vars;
	char	*map_path;

	win_init(&vars);
	map_path = MAP;
	vars.xpm_path = CLOSE;
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, map_path,
			&vars.img_width, &vars.img_height);
	mlx_key_hook(vars.win, keybutton, &vars);
	mlx_loop_hook(vars.mlx, map, &vars);
	mlx_hook(vars.win, 17, 0, exit_button, &vars);
	mlx_loop(vars.mlx);
}
