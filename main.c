/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:47:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/07/26 11:14:02 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	char	*relative_path;
	int		x;
	int		y;
}				t_data;

int	keybutton(int keycode, t_data *data)
{
	t_data	img;

	mlx_clear_window(data->mlx, data->win);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		printf("exit\n");
		exit(0);
	}
	if (keycode == 124)
	{
		mlx_pixel_put(&img, data->win, (*data).x, (*data).y, 0xFFFF00);
		(*data).x += 10;
		printf("right button %d\n", (*data).x);
	}
	else if (keycode == 123)
	{
		mlx_pixel_put(&img, data->win, (*data).x, (*data).y, 0xFFFF00);
		(*data).x -= 10;
		printf("left button %d\n", (*data).x);
	}
	else if (keycode == 126)
	{
		mlx_pixel_put(&img, data->win, (*data).x, (*data).y, 0xFFFF00);
		(*data).y -= 10;
		printf("up button %d\n", (*data).y);
	}
	else if (keycode == 125)
	{
		mlx_pixel_put(&img, data->win, (*data).x, (*data).y, 0xFFFF00);
		(*data).y += 10;
		printf("down button %d\n", (*data).y);
	}
	return (0);
}

int	main(void)
{
	t_data	img;
	t_data	data;
	int		x;
	int		y;
	int		a;
	int		b;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	data.relative_path = "./test.xpm";
	x = 960;
	y = 480;
	a = 0;
	b = 0;
	// img.img = mlx_new_image(data.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
				// &img.line_length, &img.endian);

	while (b != 200)
	{
		mlx_pixel_put(&img, data.win, x, y, 0x00FF0000);
		y++;
		b++;
	}
	while (a != 200)
	{
		mlx_pixel_put(&img, data.win, x, y, 0x0000FF00);
		x++;
		a++;
	}
	while (b != 0)
	{
		mlx_pixel_put(&img, data.win, x, y, 0xA020F0);
		y--;
		b--;
	}
	while (a != 0)
	{
		mlx_pixel_put(&img, data.win, x, y, 0x00000FF);
		x--;
		a--;
	}
	img.img = mlx_xpm_file_to_image(data.mlx, data.relative_path,
			&data.img_width, &data.img_height);
	mlx_key_hook(data.win, keybutton, &data);
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_loop(data.mlx);
}
