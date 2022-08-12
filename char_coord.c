/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:02:39 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/12 13:54:29 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character(t_vars *vars)
{
	meth(vars);
	vars->b = 0;
	wasd_animation(vars);
	while (vars->b != vars->pixel_h)
	{
		vars->a = 0;
		while (vars->a != vars->pixel_w)
		{
			if (vars->a == vars->x && vars->b == vars->y)
			{
				vars->img = mlx_xpm_file_to_image(vars->mlx, vars->xpm_path,
						&vars->img_width, &vars->img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
					vars->a, vars->b);
			}
			vars->a += 64;
		}
		vars->b += 64;
	}
	return (0);
}

void	duptostr(t_vars *vars)
{
	int	x;

	x = 0;
	vars->str = vars->dup;
	vars->coin = 0;
	while (vars->str[x])
	{
		if (vars->str[x] == 'C')
			vars->coin++;
		x++;
	}
}

void	e_filter(t_vars *vars, int x)
{
	int	tmp_e_pos;

	vars->e_y = (x / vars->map_w);
	tmp_e_pos = vars->map_w * vars->e_y;
	vars->e_x = (x - tmp_e_pos);
}
