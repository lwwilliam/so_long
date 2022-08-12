/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:34:02 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/12 12:30:22 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin(t_vars *vars)
{
	static int	frame;
	int			fps;

	fps = 22;
	frame++;
	if (frame <= fps)
		vars->coin_path = COIN1;
	else if (frame <= fps * 2)
		vars->coin_path = COIN2;
	else if (frame <= fps * 3)
		frame = 0;
	vars->coin_img = mlx_xpm_file_to_image(vars->mlx, vars->coin_path,
			&vars->img_width, &vars->img_height);
	return (0);
}

int	coin_coords2(t_vars *vars)
{
	vars->b = 0;
	while (vars->b != vars->pixel_h)
	{
		vars->a = 0;
		while (vars->a != vars->pixel_w)
		{
			if ((vars->a == vars->c_x && vars->b == vars->c_y))
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->coin_img,
					vars->a, vars->b);
			}
			vars->a += 64;
		}
		vars->b += 64;
	}
	return (0);
}

void	coin_take(t_vars *vars)
{
	char	*tmp_array;
	int		tmp_cx;
	int		tmp_cy;
	int		str_place;

	tmp_array = vars->str;
	if (vars->y == vars->c_y && vars->x == vars->c_x)
	{
		vars->coin--;
		tmp_cx = vars->x / 64 + 1;
		tmp_cy = vars->y / 64;
		str_place = ((tmp_cy * vars->map_w) + tmp_cx);
		tmp_array[str_place - 1] = 48;
		vars->str = tmp_array;
		vars->coin_collected++;
	}
}

int	coin_placement(t_vars *vars)
{
	char	*tmp_array;
	int		tmp_b_pos;
	int		len;
	int		x;

	len = ft_strlen(vars->str);
	tmp_array = vars->str;
	x = 0;
	while (tmp_array[x])
	{
		if (tmp_array[x] == 'C')
		{
			vars->c_y = (x / vars->map_w);
			tmp_b_pos = vars->map_w * vars->c_y;
			vars->c_x = (x - tmp_b_pos);
			vars->c_x *= 64;
			vars->c_y *= 64;
			coin(vars);
			coin_coords2(vars);
			coin_take(vars);
		}
		x++;
	}
	return (0);
}

// int	coin_placement(t_vars *vars)
// {
// 	vars->coin_path = COIN2;
// 	vars->coin_img = mlx_xpm_file_to_image(vars->mlx, vars->coin_path,
// 			&vars->img_width, &vars->img_height);
// 	coin(vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->coin_img,
// 		vars->c_x, vars->c_y);
// 	if (vars->x == vars->c_x && vars->y == vars->c_y)
// 	{
// 		// vars->coin_collected += 1;
// 		// printf("%d\n", vars->coin_collected);
// 	}
// 	return (0);
// }