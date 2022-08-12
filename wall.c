/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:59:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/13 00:21:41 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_placement(t_vars *vars)
{
	char	*wall_path;

	vars->b = 0;
	wall_path = WALL;
	vars->wall = mlx_xpm_file_to_image(vars->mlx, wall_path,
			&vars->img_width, &vars->img_height);
	wall_coords(vars);
	return (0);
}

int	wall_coords2(t_vars *vars)
{
	vars->b = 0;
	while (vars->b != vars->pixel_h)
	{
		vars->a = 0;
		while (vars->a != vars->pixel_w)
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

int	wall_coords(t_vars *vars)
{
	char	*tmp_array;
	int		tmp_b_pos;
	int		len;
	int		x;

	len = ft_strlen(vars->dup);
	tmp_array = vars->dup;
	x = 0;
	while (tmp_array[x])
	{
		if (tmp_array[x] == '1')
		{
			vars->w_y = (x / vars->map_w);
			tmp_b_pos = vars->map_w * vars->w_y;
			vars->w_x = (x - tmp_b_pos);
			vars->w_x *= 64;
			vars->w_y *= 64;
			wall_coords2(vars);
		}
		x++;
	}
	return (0);
}

void	pos_formula(t_vars *vars)
{
	vars->x = vars->pos_x * 64;
	vars->y = vars->pos_y * 64;
	vars->p2_x *= 64;
	vars->p2_y *= 64;
	vars->e_x *= 64;
	vars->e_y *= 64;
}
