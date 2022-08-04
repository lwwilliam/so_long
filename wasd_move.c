/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:11:58 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/04 20:43:00 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_funct(t_vars *vars)
{
	int	temp_y;
	int	temp_x;

	temp_y = vars->y - 64;
	temp_x = vars->x;
	if (vars->y > 0 && (temp_y != vars->w_y || temp_x != vars->w_x))
		vars->y -= 64;
}

void	down_funct(t_vars *vars)
{
	int	temp_y;
	int	temp_x;
	int	y;

	temp_y = vars->y + 64;
	temp_x = vars->x;
	y = vars->pixel_h - 64;
	if (vars->y < y && (temp_y != vars->w_y || temp_x != vars->w_x))
		vars->y += 64;
}

void	left_funct(t_vars *vars)
{
	int	temp_y;
	int	temp_x;

	temp_y = vars->y;
	temp_x = vars->x - 64;
	if (vars->x > 0 && (temp_y != vars->w_y || temp_x != vars->w_x))
		vars->x -= 64;
}

void	right_funct(t_vars *vars)
{
	int	temp_y;
	int	temp_x;
	int	x;

	temp_y = vars->y;
	temp_x = vars->x + 64;
	x = vars->pixel_w - 64;
	if (vars->x < x && (temp_y != vars->w_y || temp_x != vars->w_x))
		vars->x += 64;
}
