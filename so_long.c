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

int player_can_move(t_mlx_datas *vars, int x, int y)
{
	if (vars->map[y][x] == '1') // || vars->map[y][x] == 'E') <- ???
		return (0);
	return (1);
}

void move_up(t_mlx_datas *vars)
{
	vars->play_pos.y--;
}

void move_down(t_mlx_datas *vars)
{
	vars->play_pos.y++;
}

void move_left(t_mlx_datas *vars)
{
	vars->play_pos.x--;
}

void move_right(t_mlx_datas *vars)
{
	vars->play_pos.x++;
}

int key_hook_2(int keycode, t_mlx_datas *vars)
{

	if (keycode == 'd')
	{
		if (player_can_move(vars, vars->play_pos.x + 1, vars->play_pos.y))
		{
			move_right(vars);
			vars->moves++;
		}
		
	}
	if (keycode == 'a')
	{
		if (player_can_move(vars, vars->play_pos.x - 1, vars->play_pos.y))
		{
			move_left(vars);
			vars->moves++;
		}

	}
	if (keycode == 's')
	{
		if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y + 1))
		{
			move_down(vars);
			vars->moves++;
		}
	}
	if (keycode == 'w')
	{
		if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y - 1))
		{
			move_up(vars);
			vars->moves++;
		}
	}

	printf("%d\n", vars->moves); // /!\ PRINTF !
	return (0);
}

void put_free_space(t_mlx_datas *vars)
{
	if (vars->play_pos.last_x != vars->play_pos.x || vars->play_pos.last_y != \
	vars->play_pos.y)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->free_space.img, vars->play_pos.last_x * vars->player.width, vars->play_pos.last_y * vars->player.height);
		vars->play_pos.last_x = vars->play_pos.x;
		vars->play_pos.last_y = vars->play_pos.y;
	}
}

void put_player(t_mlx_datas *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->play_pos.x * vars->player.width, vars->play_pos.y * vars->player.height);
}

int render_next_frame(t_mlx_datas *vars)
{
	put_player(vars);
	put_free_space(vars);
	return (0);
}

int main(int ac, char **av)
{
	t_mlx_datas vars;
	t_map_datas map_datas;
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
	mlx_key_hook(vars.win, key_hook_2, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	init_tmp(&vars);
	init_map(&vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}