/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:41:24 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/13 00:28:06 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arguments(t_vars *vars, char **av, int ac)
{
	// char	*tmp;
	// int		x;
	// int		file;
	// int		tmp;

	if (ac != 2)
	{
		write(1, "error!!! format: ./so_long <map directory>\n", 43);
		exit(0);
	}
	if (*av[1])
		vars->map_name = av[1];
	// file = open(vars->map_name, O_RDONLY);
	// if (file == -1)
	// {
	// 	write(1, "Invalid map\n", 12);
	// 	exit(0);
	// }
	// map_read(vars);
	// tmp = vars->dup;
	// x = ft_strlen(tmp);
	// if (vars->map_h * vars->map->w != x);
	// tmp = vars->map_w * vars->map_h;
}
