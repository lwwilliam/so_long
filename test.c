/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/07/26 11:45:37 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
	void	*img;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	char	*relative_path;
	int		x;
	int		y;
}				t_vars;

int	keybutton(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("exit\n");
		exit(0);
	}
	if (keycode == 49)
	{
		mlx_clear_window(vars->mlx, vars->win);
	}
	return (0);
}

int	next_frame(t_vars *vars)
{
	t_vars	img;
	t_vars	x;
	t_vars	y;

	x.x = 0;
	y.y = 0;
	vars->relative_path = "./test.xpm";
	while (x.x != 100)
	{
		img.img = mlx_xpm_file_to_image(vars->mlx, vars->relative_path,
				&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, x.x, y.y);
		// mlx_clear_window(vars->mlx, vars->win);
		x.x++;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, keybutton, &vars);
	mlx_loop_hook(vars.mlx, next_frame, &vars);
	mlx_loop(vars.mlx);
}
