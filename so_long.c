/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/04 21:06:15 by lwilliam         ###   ########.fr       */
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
	enemy_placement(vars);
	character(vars);
	return (0);
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	printf("11w: %d, h: %d, x: %d, y: %d\n11", vars->map_w, vars->map_h, vars->pixel_w, vars->pixel_h);
	vars->win = mlx_new_window(vars->mlx, vars->pixel_w,
			vars->pixel_h, "So_long!");
	vars->x = 0;
	vars->y = 0;
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*map_path;

	map_size(&vars);
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

void	map_read(t_vars *vars)
{
	int		fd;
	char	*line;

	vars->map_w = 0;
	vars->map_h = 0;
	fd = open("./maps/test.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		// printf("%s\n", line);
		vars->map_w = ft_strlen(line);
		// printf("len: %i\n", vars->map_w);
		vars->map_h++;
		line = get_next_line(fd);
	}
	fd = close(fd);
}
