/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:47:53 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/12 20:18:19 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_placement(t_vars *vars)
{
	char	*exit_path;
	void	*exit_img;

	exit_path = EXIT;
	exit_img = mlx_xpm_file_to_image(vars->mlx, exit_path,
			&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, exit_img,
		vars->e_x, vars->e_y);
	if (vars->x == vars->e_x && vars->y == vars->e_y)
	{
		if (vars->coin == 0)
		{
			write(1, "=================================\n", 34);
			write(1, "number of movement: ", 20);
			ft_putnbr(vars->n_of_m);
			write(1, "\n", 1);
			write(1, "You WON!!\n", 11);
			write(1, "=================================\n", 34);
			exit(0);
		}
	}
	return (0);
}
