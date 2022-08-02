/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ani.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:08:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/02 12:28:00 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	w_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame == FRAME)
		vars->xpm_path = CLOSE;
	if (frame >= FRAME * 2)
		vars->xpm_path = OPEN3;
	if (frame >= FRAME * 3)
	{
		vars->xpm_path = OPEN4;
		frame = 0;
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->xpm_path,
			&vars->img_width, &vars->img_height);
	return (0);
}

int	a_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame == FRAME)
		vars->xpm_path = CLOSE;
	if (frame >= FRAME * 2)
		vars->xpm_path = OPEN5;
	if (frame >= FRAME * 3)
	{
		vars->xpm_path = OPEN6;
		frame = 0;
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->xpm_path,
			&vars->img_width, &vars->img_height);
	return (0);
}

int	s_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame == FRAME)
		vars->xpm_path = CLOSE;
	if (frame >= FRAME * 2)
		vars->xpm_path = OPEN7;
	if (frame >= FRAME * 3)
	{
		vars->xpm_path = OPEN8;
		frame = 0;
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->xpm_path,
			&vars->img_width, &vars->img_height);
	return (0);
}

int	d_animation(t_vars *vars)
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

int	wasd_animation(t_vars *vars)
{
	if (vars->kkk == 3)
		w_animation(vars);
	if (vars->kkk == 4)
		a_animation(vars);
	if (vars->kkk == 1)
		s_animation(vars);
	if (vars->kkk == 2)
		d_animation(vars);
	return (0);
}

int	character(t_vars *vars)
{
	vars->b = 0;
	wasd_animation(vars);
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
	printf("%d %d\n", vars->x, vars->y);
	return (0);
}
