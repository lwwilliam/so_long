/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 12:58:50 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map(t_vars *vars)
{
	vars->b = 0;
	while (vars->b != vars->pixel_h)
	{
		vars->a = 0;
		while (vars->a != vars->pixel_w)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				vars->a, vars->b);
			vars->a += 64;
		}
		vars->b += 64;
	}
	wall_placement(vars);
	exit_placement(vars);
	enemy_placement(vars);
	coin_placement(vars);
	character(vars);
	num_move(vars);
	return (0);
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->pixel_w,
			vars->pixel_h, "So_long!");
	vars->coin_collected = 0;
	vars->n_of_m = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*map_path;

	arguments(&vars, av, ac);
	map_size(&vars);
	free(vars.dup);
	item_pos(&vars);
	win_init(&vars);
	map_path = MAP;
	vars.xpm_path = CLOSE;
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, map_path,
			&vars.img_width, &vars.img_height);
	mlx_loop_hook(vars.mlx, map, &vars);
	mlx_key_hook(vars.win, keybutton, &vars);
	duptostr(&vars);
	mlx_hook(vars.win, 17, 0, exit_button, &vars);
	mlx_loop(vars.mlx);
}

int	map_size(t_vars *vars)
{
	vars->pixel_w = 0;
	vars->pixel_h = 0;
	map_read(vars);
	map_error(vars);
	if (vars->map_w != 0)
		vars->pixel_w = vars->map_w * 64;
	if (vars->map_h != 0)
		vars->pixel_h = vars->map_h * 64;
	return (0);
}
// int	map_read(t_vars *vars)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./maps/test.ber", O_RDONLY);
// 	line = " ";
// 	printf("%s\n", line);
// 	fd = close(fd);
// 	return (0);
// }
