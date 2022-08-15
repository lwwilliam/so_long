/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:29:37 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 10:51:27 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	num_move(t_vars *vars)
{
	char	*tmp;

	tmp = ft_itoa(vars->n_of_m);
	mlx_string_put(vars->mlx, vars->win, 0, 0,
		9761790, "number of movement: ");
	mlx_string_put(vars->mlx, vars->win, 64 * 3, 0,
		9761790, tmp);
	free (tmp);
}
