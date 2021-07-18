/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:49:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 13:28:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tmp(t_mlx_datas *vars)
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

void	put_animated_movements(t_mlx_datas*vars)
{
	if (vars->play_pos.down == 1)
		move_down(vars);
	if (vars->play_pos.up == 1)
		move_up(vars);
	if (vars->play_pos.left == 1)
		move_left(vars);
	if (vars->play_pos.right == 1)
		move_right(vars);
}

int	render_next_frame(t_mlx_datas *vars)
{
	static int i = 0;

	i++;
	if (i == 1500)
		put_animated_movements(vars);
	if (i == 7500)
	{
		// put_free_space(vars);
		put_collectible(vars);
		
		i = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_datas	vars;
	t_map_datas	map_datas;
	char		**map;

	if (check_params(ac, av) == -1)
		return (-1);
	map = map_parser(&map_datas, av[1]);
	if (error_msg(map, "Invalid map.\n"))
		return (-1);
	vars.map_datas = map_datas;
	vars.map = map;
	if (init_mlx_datas_struct(&vars) == -1)
		return (-1);
	mlx_key_hook(vars.win, mov_key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars); // utiliser close_win dans mlx_key_hook ???
	init_tmp(&vars);
	init_map(&vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	exit(1);
	return (0);
}