/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:59:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/02 12:05:14 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_placement(t_vars *vars)
{
	char	*wall_path;

	vars->w_x = 0;
	vars->w_y = 0;
	vars->b = 0;
	wall_path = WALL;
	vars->wall = mlx_xpm_file_to_image(vars->mlx, wall_path,
			&vars->img_width, &vars->img_height);
	while (vars->w_x != 640 && vars->w_y != 640)
	{
		vars->w_x += 64;
		vars->w_y += 64;
	}
	wall_coords(vars);
	return (0);
}

int	wall_coords(t_vars *vars)
{
	vars->b = 0;
	while (vars->b != 1024)
	{
		vars->a = 0;
		while (vars->a != 1920)
		{
			if ((vars->a == vars->w_x && vars->b == vars->w_y))
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
					vars->a, vars->b);
			}
			vars->a += 64;
		}
		vars->b += 64;
	}
	return (0);
}
