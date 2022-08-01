/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybuttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:23:26 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/01 13:29:18 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	write(0, "Exit\n", 5);
	exit(0);
}

int	right_funct(t_vars *vars)
{
	if (vars->x < 1856)
		vars->x += 64;
	return (0);
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

int	keybutton(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_button(vars);
	if (keycode == 2)
		right_funct(vars);
	if (keycode == 0)
		if (vars->x > 0)
			vars->x -= 64;
	if (keycode == 1)
		if (vars->y < 960)
			vars->y += 64;
	if (keycode == 13)
		if (vars->y > 0)
			vars->y -= 64;
	key_read(keycode, vars);
	return (0);
}
