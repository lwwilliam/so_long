/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/07/22 10:32:47 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	keybutton(int keycode, t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("fuck\n");
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, keybutton, &vars);
	mlx_loop(vars.mlx);
}
