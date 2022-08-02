/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:33:26 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/02 11:12:50 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy(t_vars *vars)
{
	static int	frame;
	int			fps;

	fps = 12;
	frame++;
	if (frame <= fps)
		vars->enemy_path = GHOST1;
	else if (frame <= fps * 2)
		vars->enemy_path = GHOST2;
	else if (frame <= fps * 3)
		frame = 0;
	vars->enemy_img = mlx_xpm_file_to_image(vars->mlx, vars->enemy_path,
			&vars->img_width, &vars->img_height);
	return (0);
}

int	enemy_placement(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->enemy_path = GHOST2;
	enemy(vars);
	while (x != 320 && y != 320)
	{
		x += 64;
		y += 64;
	}
	if (x == 320 && y == 320)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_img,
			x, y);
	}
	if (vars->x == x && vars->y == y)
	{
		write(1, "Get good SCRUB!!\n", 18);
		exit(0);
	}
	return (0);
}
