/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/01 12:34:59 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map(t_vars *vars)
{
	vars->b = 0;
	while (vars->b != 1024)
	{
		vars->a = 0;
		while (vars->a != 1920)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				vars->a, vars->b);
			vars->a += 64;
		}
		vars->b += 64;
	}
	character(vars);
	return (0);
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	vars->x = 0;
	vars->y = 0;
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*map_path;

	win_init(&vars);
	map_path = MAP;
	vars.xpm_path = CLOSE;
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, map_path,
			&vars.img_width, &vars.img_height);
	mlx_key_hook(vars.win, keybutton, &vars);
	mlx_loop_hook(vars.mlx, map, &vars);
	mlx_hook(vars.win, 17, 0, exit_button, &vars);
	mlx_loop(vars.mlx);
}
