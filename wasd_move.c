/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:11:58 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/13 00:22:19 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	meth(t_vars *vars)
{
	int		str_x;
	int		str_y;

	str_y = vars->y / 64;
	str_x = vars->x / 64 + 1;
	vars->str_pos = ((str_y * vars->map_w) + str_x);
}

void	up_funct(t_vars *vars)
{
	char	*tmp_array;

	tmp_array = vars->dup;
	if (tmp_array[vars->str_pos - (vars->map_w + 1)] != '1')
	{
		vars->y -= 64;
		vars->n_of_m++;
	}
	w_animation(vars);
}

void	down_funct(t_vars *vars)
{
	char	*tmp_array;

	tmp_array = vars->dup;
	if (tmp_array[vars->str_pos + (vars->map_w - 1)] != '1')
	{
		vars->y += 64;
		vars->n_of_m++;
	}
	s_animation(vars);
}

void	left_funct(t_vars *vars)
{
	char	*tmp_array;

	tmp_array = vars->dup;
	if (tmp_array[vars->str_pos - 2] != '1')
	{
		vars->x -= 64;
		vars->n_of_m++;
	}
	a_animation(vars);
}

void	right_funct(t_vars *vars)
{
	char	*tmp_array;

	tmp_array = vars->dup;
	if (tmp_array[vars->str_pos] != '1')
	{
		vars->x += 64;
		vars->n_of_m++;
	}
	d_animation(vars);
}

// void	print_test(t_vars *vars)
// {
// 	char	*tmp_array;
// 	int		x;

// 	tmp_array = vars->dup;
// 	x = vars->str_pos;
// 	printf("%s\n", tmp_array);
// 	printf("test : %d\n", vars->str_pos);
// 	printf("x : %d\n", (vars->map_w));
// 	printf("up   : %c\n", tmp_array[vars->str_pos - (vars->map_w + 1)]);
// 	printf("down : %c\n", tmp_array[vars->str_pos + (vars->map_w - 1)]);
// 	printf("left : %c\n", tmp_array[vars->str_pos - 2]);
// 	printf("right: %c\n", tmp_array[vars->str_pos]);
// }
