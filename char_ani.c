/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ani.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:08:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/01 12:26:01 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
