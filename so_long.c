/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:49:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/14 22:24:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_tmp(t_mlx_datas *vars)
{
	vars->free_space.x = 0;
	vars->free_space.y = 0;
	vars->wall.x = 0;
	vars->wall.y = 0;
	vars->collectible.x = 0;
	vars->collectible.y = 0;
	vars->player.x = 0;
	vars->player.y = 0;
	vars->exit.x = 0;
	vars->exit.y = 0;
}

int key_hook(int keycode, t_mlx_datas *vars)
{
	vars->last_x_pos = vars->player.x;
	vars->last_y_pos = vars->player.y;
	if (keycode == 'd')
	{
		vars->player.x += vars->player.width;
		if (vars->player.x < 0)
			vars->player.x = 0;
		else if (vars->player.x > vars->win_size_x - vars->player.width)
			vars->player.x = vars->win_size_x - vars->player.width;
	}
	if (keycode == 'a')
	{
		vars->player.x -= vars->player.width;
		if (vars->player.x < 0)
			vars->player.x = 0;
		else if (vars->player.x > vars->win_size_x - vars->player.width)
			vars->player.x = vars->win_size_x - vars->player.width;
	}
	if (keycode == 's')
	{
		vars->player.y += vars->player.height;
		if (vars->player.y < 0)
			vars->player.y = 0;
		else if (vars->player.y > vars->win_size_y - vars->player.height)
			vars->player.y = vars->win_size_y - vars->player.height;
	}
	if (keycode == 'w')
	{
		vars->player.y -= vars->player.height;
		if (vars->player.y < 0)
			vars->player.y = 0;
		else if (vars->player.y > vars->win_size_y - vars->player.height)
			vars->player.y = vars->win_size_y - vars->player.height;
	}
	vars->moves++;
	printf("%d\n", vars->moves);
	return (0);
}

void put_free_space(t_mlx_datas *vars)
{
	if (vars->moves != 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->free_space.img, vars->last_x_pos, vars->last_y_pos);
	}
}

void put_collectible(t_mlx_datas *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, 280, 210);
}

void put_player(t_mlx_datas *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.x, vars->player.y);
}

int render_next_frame(t_mlx_datas *vars)
{
	put_player(vars);
	put_free_space(vars);
	put_collectible(vars);
	return (0);
}

int get_line_number(char *file)
{
	int size;
	int fd;
	int ret;
	char *tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 1;
	ret = get_next_line(fd, &tmp);
	while (ret != 0)
	{
		if (ret == -1)
			return (-1);
		ret = get_next_line(fd, &tmp);
		size++;
	}
	close(fd);
	return (size);
}

int fill_map(char *file, char **map)
{
	int i;
	int fd;
	int ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &map[0]);
	i = 1;
	while (ret != 0)
	{
		if (ret == -1)
			return (-1);
		ret = get_next_line(fd, &map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (0);
}

char **map_check(t_map_datas *map_datas, char *file)
{
	int size;
	char **map;

	size = get_line_number(file);
	if (size == -1)
		return (NULL);
	map = malloc(sizeof(char *) * size + 1);
	if (error_msg(map, "Memory allocation has failed.\n"))
		return (NULL);
	if (fill_map(file, map) == -1)
		return (NULL);
	init_map_datas_struct(map_datas);
	return (map);
}

int main(int ac, char **av)
{
	t_mlx_datas vars;
	t_map_datas map_datas;
	char		**map;

	if (check_params(ac, av) == -1)
		return (-1);
	map = map_check(&map_datas, av[1]);
	if (error_msg(map, "Invalid map.\n") == -1)
		return (-1);
	if (init_mlx_datas_struct(&vars) == -1)
		return (-1);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	init_tmp(&vars);
	init_map(&vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}