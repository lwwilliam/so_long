/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:14:36 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/05 12:26:12 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			x;
	unsigned char	*str;

	x = 0;
	str = (unsigned char *)s;
	while (x < n)
	{
		str[x] = 0;
		x++;
	}
}
