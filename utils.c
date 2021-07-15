/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:54:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/14 21:46:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int init_img_datas_struct(t_mlx_datas *vars)
{
	vars->free_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/freespace.xpm", &vars->free_space.width, &vars->free_space.height);
	vars->free_space.x = 0;
	vars->free_space.y = 0;
	if (error_msg(vars->free_space.img, "Image reading has failed.\n"))
		return (-1);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/wall.xpm", &vars->wall.width, &vars->wall.height);
	vars->wall.x = 0;
	vars->wall.y = 0;
	if (error_msg(vars->wall.img, "Image reading has failed.\n"))
		return (-1);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/collectible.xpm", &vars->collectible.width, &vars->collectible.height);
	vars->collectible.x = 0;
	vars->collectible.y = 0;
	if (error_msg(vars->collectible.img, "Image reading has failed.\n"))
		return (-1);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/player.xpm", &vars->player.width, &vars->player.height);
	vars->player.x = 0;
	vars->player.y = 0;
	if (error_msg(vars->player.img, "Image reading has failed.\n"))
		return (-1);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/exit.xpm", &vars->exit.width, &vars->exit.height);
	vars->exit.x = 0;
	vars->exit.y = 0;
	if (error_msg(vars->exit.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int init_mlx_datas_struct(t_mlx_datas *vars)
{
	vars->mlx = mlx_init();
	if (error_msg(vars->mlx, "mlx_init has failed.\n"))
		return (0);
	vars->last_x_pos = 0;
	vars->last_y_pos = 0;
	vars->moves = 0;
	if (init_img_datas_struct(vars) == -1)
		return (-1);
	vars->win_size_x = vars->free_space.width * 13;// change the multiplicater in accordance 
	vars->win_size_y = vars->free_space.height * 8;// with the map given as parameter
	vars->win = mlx_new_window(vars->mlx, vars->win_size_x, vars->win_size_y, "so_long");
	if (error_msg(vars->win, "Opening a new window has failed.\n"))
		return (0);
	vars->free_space.tmp = 0;
	vars->wall.tmp = 0;
	vars->collectible.tmp = 0;
	vars->player.tmp = 0;
	vars->exit.tmp = 0;
	return (0);
}

void init_map_datas_struct(t_map_datas *map)
{
	map->width = 0;
	map->height = 0;
	map->collectible = 0;
	map->player = 0;
	map->exit = 0;
}

void init_map(t_mlx_datas *vars)
{
	int x;
	int y;

	x = 0;
	while (x < vars->win_size_x)
	{
		y = 0;
		while (y < vars->win_size_y)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
									vars->free_space.img, x, y);
			y = y + vars->free_space.height;
		}
		x = x + vars->free_space.width;
	}
	vars->tmp_free_space = 1;
}

static int check_extension(char *file)
{
	int i;
	int check;

	i = 0;
	while(file[i] != '\0')
		i++;
	if (i == 0)
		return (-1);
	i--;
	check = 0;
	while (i != 0 && check != 4)
	{
		if (check == 0 && file[i] == 'r')
			i--;
		else if (check == 1 && file [i] == 'e')
			i--;
		else if (check == 2 && file[i] == 'b')
			i--;
		else if (check == 3 && file[i] == '.')
			i--;
		else
			return (-1);
		check++;
	}
	if (check != 4)
		return (-1);
	return (0);
}

int check_params(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Please give a map with a .ber extension.\n");
		return (-1);
	}
	else if (ac > 2)
	{
		printf("Please give only one argument.\n");
		return (-1);
	}
	else
	{
		if (check_extension(av[1]) == -1)
		{
			printf("Please give a file with the right extension (.ber).\n");
			return (-1);
		}
	}
	return (0);
}

int error_msg(void *ptr, char *msg)
{
	if (ptr == NULL)
	{
		printf("%s", msg);
		return (1);
	}
	return (0);
}

int close_win(int keycode, t_mlx_datas *vars)
{
	if (keycode == 65307)
	{
		printf("Window closed.\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}