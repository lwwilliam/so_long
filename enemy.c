/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:33:26 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/17 11:31:19 by lwilliam         ###   ########.fr       */
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
	vars->enemy_path = GHOST2;
	enemy(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_img,
		vars->p2_x, vars->p2_y);
	if (vars->x == vars->p2_x && vars->y == vars->p2_y)
	{
		write(1, "=================================\n", 34);
		write(1, "number of movement: ", 20);
		ft_putnbr(vars->n_of_m);
		write(1, "\n", 1);
		write(1, "You lost!!\n", 11);
		write(1, "=================================\n", 34);
		exit(0);
	}
	return (0);
}
