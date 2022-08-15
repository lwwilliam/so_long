/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 21:57:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 12:50:15 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_vars *vars)
{
	char	*tmp;
	int		tmp_len;
	int		x;
	int		count;

	tmp = vars->dup;
	tmp_len = ft_strlen(tmp);
	x = vars->map_w * vars->map_h;
	count = 0;
	if (x != tmp_len)
		error_exit(vars);
	while (tmp[count] && count != vars->map_w)
	{
		if (tmp[count] != '1')
			error_exit(vars);
		count++;
	}
	count = x - vars->map_w;
	while (tmp[count])
	{
		if (tmp[count] != '1')
			error_exit(vars);
		count++;
	}
	map_error2(vars);
}

void	map_error2(t_vars *vars)
{
	char	*tmp;
	int		count;
	int		x;

	tmp = vars->dup;
	x = 1;
	count = vars->map_w;
	if (tmp[0] != '1')
		error_exit(vars);
	while (x != vars->map_h)
	{
		if (tmp[count * x] != '1')
			error_exit(vars);
		x++;
	}
	x = 1;
	count = vars->map_w;
	while (x != vars->map_h)
	{
		if (tmp[(count * x) - 1] != '1')
			error_exit(vars);
		x++;
	}
	map_error3(vars);
}

void	map_error3(t_vars *vars)
{
	char	*tmp;
	int		x;
	int		coin;
	int		play;
	int		end;

	tmp = vars->dup;
	x = 0;
	coin = 0;
	play = 0;
	end = 0;
	while (tmp[x])
	{
		if (tmp[x] == 'C')
			coin++;
		if (tmp[x] == 'P')
			play++;
		if (tmp[x] == 'E')
			end++;
		x++;
	}
	map_error4(coin, play, end);
}

void	map_error4(int coin, int play, int end)
{
	if (coin < 1)
	{
		write(1, "Must contain at least one 'C' (collectibles)\n", 45);
		exit(0);
	}
	if (play < 1)
	{
		write(1, "Must contain at least one 'P' (player's starting position)\n", 59);
		exit(0);
	}
	if (play > 1)
	{
		write(1, "Map contain more than one 'P' (player's starting position)\n", 59);
		exit(0);
	}
	if (end < 1)
	{
		write(1, "Must contain at least one 'E' (map exit)\n", 41);
		exit(0);
	}
	if (end > 1)
	{
		write(1, "Map contain more than one 'E' (map exit)\n", 41);
		exit(0);
	}
}
