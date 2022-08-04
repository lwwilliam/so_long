/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:02:39 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/04 20:01:41 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character(t_vars *vars)
{
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
	printf("%d , %d\n", vars->x, vars->y);
	return (0);
}
