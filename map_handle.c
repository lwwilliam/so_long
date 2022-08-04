/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:13:05 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/04 21:07:20 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	map_height(t_vars *vars)
// {
// 	int	height;

// 	while (&map_read == NULL)
// 		height++;
// 	return (height);
// }

int	map_size(t_vars *vars)
{
	vars->pixel_w = 0;
	vars->pixel_h = 0;
	map_read(vars);
	if (vars->map_w != 0)
		vars->pixel_w = vars->map_w * 64;
	if (vars->map_h != 0)
		vars->pixel_h = vars->map_h * 64;
	printf("w: %d, h: %d, x: %d, y: %d\n", vars->map_w, vars->map_h, vars->pixel_w, vars->pixel_h);
	return (0);
}

void	play_pos(t_vars *vars)
{
	int	pos_x;
	int	pos_y;

	pos_x = map_w;
	pos_y = map_h
	if ()
}
