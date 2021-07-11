/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:44:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/11 21:56:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <unistd.h>

/*
** Compilation :
** clang test.c -lXext -lX11 -lm -lbsd minilibx-linux/libmlx_Linux.a
*/

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixels;
	int	line_length;
	int	endian;
}		t_data;

int deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
	*(unsigned int *)dst = color;
}

int main()
{
	int	i;
	int	j;
	void	*mlx_init_ptr;
	void	*mlx_win;
	t_data	img;

	mlx_init_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_init_ptr, 960, 540, "Hello world !");
	img.img = mlx_new_image(mlx_init_ptr, 960, 540);
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello world!");
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, \
			&img.line_length, &img.endian);
	i = 20;
	j  = 20;
	while (i < 275)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		i++;
	}
	while (j < 275)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		j++;
	}
	while (i >= 20 )
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		i--;
	}
	while (j >= 20)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		j--;
	}
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
	i = 100;
	j  = 100;
	while (i < 375)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		i++;
	}
	while (j < 375)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		j++;
	}
	while (i >= 100)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		i--;
	}
	while (j >= 100)
	{
		pixel_put(&img, i, j, 0x00ff0000);
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
		j--;
	}
	mlx_put_image_to_window(mlx_init_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_init_ptr);
	return (0);
}
