/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:49:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 00:36:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_animated_movements(t_mlx_datas *vars)
{
	if (vars->play_pos.down == 1)
	{
		if (vars->play_pos.look_right == 1)
			move_down_right(vars);
		else
			move_down_left(vars);
	}
	if (vars->play_pos.up == 1)
	{
		if (vars->play_pos.look_right == 1)
			move_up_right(vars);
		else
			move_up_left(vars);
	}
	if (vars->play_pos.left == 1)
		move_left(vars);
	if (vars->play_pos.right == 1)
		move_right(vars);
}

int	render_next_frame(t_mlx_datas *vars)
{
	static int	i = 0;

	i++;
	if (i == 1500)
	{
		if (vars->play_pos.won == 2)
			win_animation(vars);
		else if (vars->play_pos.won == 1)
			tobi_tp_animation(vars);
		else if (vars->play_pos.lost == 2)
			madara_atk_animation(vars);
		else if (vars->play_pos.lost == 1)
			lost_animation(vars);
		else
			put_animated_movements(vars);
	}
	if (i == 7500)
	{
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

	map = NULL;
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
	init_map(&vars); // Add close window with cross
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	free_all_vars(&vars);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	//exit(1);
	return (0);
}
