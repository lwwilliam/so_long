/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:38:54 by lwilliam          #+#    #+#             */
/*   Updated: 2022/07/22 14:00:19 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
