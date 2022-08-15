/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:13:05 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/15 14:14:23 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_vars *vars)
{
	int		fd;
	char	*tmp_line;

	vars->map_w = 0;
	vars->map_h = 0;
	fd = open(vars->map_name, O_RDONLY);
	tmp_line = get_next_line(fd);
	while (tmp_line != NULL)
	{
		vars->map_w = ft_strlen(tmp_line);
		vars->map_h++;
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	free(tmp_line);
	close(fd);
	array(vars);
}

void	array(t_vars *vars)
{
	int		fd;
	int		map_len;
	char	*str;

	map_len = vars->map_h * vars->map_w;
	fd = open(vars->map_name, O_RDONLY);
	vars->line = get_next_line(fd);
	vars->dup = malloc(sizeof(char) * (map_len + 1));
	*vars->dup = 0;
	while (vars->line != NULL)
	{
		str = ft_strtrim((char *)vars->line, "\n");
		free(vars->line);
		vars->line = ft_strdup(vars->dup);
		free (vars->dup);
		vars->dup = ft_strjoin(vars->line, str);
		free (str);
		free (vars->line);
		vars->line = get_next_line(fd);
	}
	free(vars->line);
	close(fd);
}

void	p_filter(t_vars *vars, int x)
{
	int	tmp_pos_y;

	vars->pos_y = (x / vars->map_w);
	tmp_pos_y = vars->map_w * vars->pos_y;
	vars->pos_x = (x - tmp_pos_y);
}

void	b_filter(t_vars *vars, int x)
{
	int	tmp_b_pos;

	vars->p2_y = (x / vars->map_w);
	tmp_b_pos = vars->map_w * vars->p2_y;
	vars->p2_x = (x - tmp_b_pos);
}

void	item_pos(t_vars *vars)
{
	char	*tmp_dup;
	int		x;
	int		len;

	len = ft_strlen(vars->dup);
	tmp_dup = malloc(sizeof(char) * (len + 1));
	vars->pos_x = 0;
	vars->pos_y = 0;
	tmp_dup = vars->dup;
	x = 0;
	while (tmp_dup[x])
	{
		if (tmp_dup[x] == 'P')
			p_filter(vars, x);
		if (tmp_dup[x] == 'B')
			b_filter(vars, x);
		if (tmp_dup[x] == 'E')
			e_filter(vars, x);
		x++;
	}
	pos_formula(vars);
}
