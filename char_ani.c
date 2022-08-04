/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ani.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:08:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/02 15:02:38 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	w_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame <= FRAME)
		vars->xpm_path = CLOSE;
	else if (frame <= FRAME * 2)
		vars->xpm_path = OPEN3;
	else if (frame <= FRAME * 3)
	{
		vars->xpm_path = OPEN4;
		frame = 0;
	}
	return (0);
}

int	a_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame <= FRAME)
		vars->xpm_path = CLOSE;
	else if (frame <= FRAME * 2)
		vars->xpm_path = OPEN5;
	else if (frame <= FRAME * 3)
	{
		vars->xpm_path = OPEN6;
		frame = 0;
	}
	return (0);
}

int	s_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame <= FRAME)
		vars->xpm_path = CLOSE;
	else if (frame <= FRAME * 2)
		vars->xpm_path = OPEN7;
	else if (frame <= FRAME * 3)
	{
		vars->xpm_path = OPEN8;
		frame = 0;
	}
	return (0);
}

int	d_animation(t_vars *vars)
{
	static int	frame;

	frame++;
	if (frame <= FRAME)
		vars->xpm_path = CLOSE;
	else if (frame <= FRAME * 2)
		vars->xpm_path = OPEN1;
	else if (frame <= FRAME * 3)
	{
		vars->xpm_path = OPEN2;
		frame = 0;
	}
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
