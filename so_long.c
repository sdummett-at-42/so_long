/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:49:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:22:20 by sdummett         ###   ########.fr       */
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

static void	put_sprites(t_mlx_datas *vars, char c, int x, int y)
{
	if (c == '1')
		init_put_wall(vars, x, y);
	else if (c == '0')
		init_put_free_space(vars, x, y);
	else if (c == 'E')
		init_put_exit(vars, x, y);
	else if (c == 'M')
		init_put_madara(vars, x, y);
}

void	refresh_map(t_mlx_datas *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = 0;
	put_ath(vars);
	while (vars->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (vars->map[i][j] != '\0')
		{
			put_sprites(vars, vars->map[i][j], x, y);
			if (vars->map[i][j] == 'P')
				init_put_player(vars, x, y);
			if (vars->play_pos.is_moving == 0 && vars->play_pos.won == 0 \
				&& vars->play_pos.lost == 0)
			x = x + vars->height;
			j++;
		}
		y = y + vars->width;
		i++;
	}
}

int	render_next_frame(t_mlx_datas *vars)
{
	static int	i = 0;

	i++;
	if (i == 900)
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
		if (vars->play_pos.is_moving == 0 && vars->play_pos.won == 0 \
			&& vars->play_pos.lost == 0)
			refresh_map(vars);
	}
	if (i == 1200)
	{
		put_collectible(vars);
		i = 0;
	}
	return (0);
}

static void	clean_all(t_mlx_datas *vars)
{
	free_all_vars(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_putstr("Window closed.\n");
	free(vars->mlx);
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
	if (error_msg(map, "Error\nInvalid map.\n"))
		return (-1);
	vars.map_datas = map_datas;
	vars.map = map;
	if (init_mlx_datas_struct(&vars) == -1)
		return (-1);
	mlx_key_hook(vars.win, mov_key_hook, &vars);
	init_map(&vars);
	init_map_ath(&vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win_cross, &vars);
	mlx_loop(vars.mlx);
	clean_all(&vars);
	return (0);
}
