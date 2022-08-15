/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybuttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:23:26 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 14:14:17 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_button(t_vars *vars)
{
	write(1, "=================================\n", 34);
	write(1, "number of movement: ", 20);
	ft_putnbr(vars->n_of_m);
	write(1, "\n", 1);
	write(1, "=================================\n", 34);
	mlx_destroy_window(vars->mlx, vars->win);
	write(0, "Exit\n", 5);
	exit(0);
}

int	key_read(int key, t_vars *vars)
{
	vars->kkk = 0;
	if (key == 1)
		vars->kkk = 1;
	if (key == 2)
		vars->kkk = 2;
	if (key == 13)
		vars->kkk = 3;
	if (key == 0)
		vars->kkk = 4;
	return (0);
}

void	keybutton2(int keycode, t_vars *vars)
{
	if (keycode == 126)
		if (vars->p2_y > 0)
			vars->p2_y -= 64;
	if (keycode == 123)
		if (vars->p2_x > 0)
			vars->p2_x -= 64;
	if (keycode == 124)
		if (vars->p2_x < (vars->map_w * 64) - 64)
			vars->p2_x += 64;
	if (keycode == 125)
		if (vars->p2_y < (vars->map_h * 64) - 64)
			vars->p2_y += 64;
}

int	keybutton(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_button(vars);
	if (keycode == 2)
	{
		right_funct(vars);
		key_read(keycode, vars);
	}
	if (keycode == 0)
	{
		left_funct(vars);
		key_read(keycode, vars);
	}
	if (keycode == 1)
	{
		down_funct(vars);
		key_read(keycode, vars);
	}
	if (keycode == 13)
	{
		up_funct(vars);
		key_read(keycode, vars);
	}
	keybutton2(keycode, vars);
	return (0);
}
