/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ani.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:08:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 14:19:27 by lwilliam         ###   ########.fr       */
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
	if (vars->kkk == 3 || vars->kkk == 0)
		w_animation(vars);
	else if (vars->kkk == 4 || vars->kkk == 0)
		a_animation(vars);
	else if (vars->kkk == 1 || vars->kkk == 0)
		s_animation(vars);
	else if (vars->kkk == 2 || vars->kkk == 0)
		d_animation(vars);
	return (0);
}
