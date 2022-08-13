/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:41:24 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/13 21:55:51 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arguments(t_vars *vars, char **av, int ac)
{
	int		file;

	if (ac != 2)
	{
		write(1, "Error!!! format: ./so_long <map directory>\n", 43);
		exit(0);
	}
	if (*av[1])
		vars->map_name = av[1];
	file = open(vars->map_name, O_RDONLY);
	if (file == -1)
	{
		write(1, "Invalid map\n", 12);
		exit(0);
	}
}

void	error_exit(t_vars *vars)
{
	vars->for_werror = 0;

	write(1, "MAP ERROR!\n", 11);
	exit(0);
}
