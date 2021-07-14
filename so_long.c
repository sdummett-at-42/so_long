/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:49:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/14 13:04:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_mlx_datas *vars)
{
	printf("keycode is %c\n", keycode);
	if (keycode == 'd')
	{
		vars->x += 10;
		if (vars->x < 0)
			vars->x = 0;
		else if (vars->x > vars->win_size_x - 5)
			vars->x = vars->win_size_x - 5;
	}
	if (keycode == 'a')
	{
		vars->x -= 10;
		if (vars->x < 0)
			vars->x = 0;
		else if (vars->x > vars->win_size_x - 5)
			vars->y = vars->win_size_x - 5;
	}
	if (keycode == 's')
	{
		vars->y += 10;
		if (vars->y < 0)
			vars->y = 0;
		else if (vars->y > vars->win_size_y - 5)
			vars->y = vars->win_size_y - 5;
	}
	if (keycode == 'w')
	{
		vars->y -= 10;
		if (vars->y < 0)
			vars->y = 0;
		else if (vars->y > vars->win_size_y - 5)
			vars->y = vars->win_size_y - 5;
	}
	return (0);
}

int render_next_frame(t_mlx_datas *vars)
{

	vars->x = 0;
	while (vars->x < vars->win_size_x)
	{
		vars->y = 0;
		while (vars->y < vars->win_size_y)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
			vars->y = vars->y + vars->height;
		}
		//printf("x : %d, y : %d, img_x : %d, win_y : %d, \n",vars->x, vars->y, \
		//vars->win_size_x, vars->win_size_y);
		vars->x = vars->x + vars->width;
	}
	return (0);
}

int main()
{
	t_mlx_datas vars;
	// t_img_datas img;

	vars.x = 0;
	vars.y = 0;
	vars.mlx = mlx_init();
	if (error_msg(vars.mlx, "mlx_init has failed.\n"))
		return (0);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "img/freespace.xpm", &vars.width, &vars.height);
	if (error_msg(vars.img, "Image reading has failed.\n"))
		return (0);
	vars.win_size_x = vars.width * 13; // change the multiplicater in 
	//accordance with the map given as parameter
	vars.win_size_y = vars.height * 8;
	vars.win = mlx_new_window(vars.mlx, vars.win_size_x, vars.win_size_y, "pepe");
	if (error_msg(vars.win, "Open a new window has failed.\n"))
		return (0);
	printf("Image -> width : %d, height : %d\n", vars.width, vars.height);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}