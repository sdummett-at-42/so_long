/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:23:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:59:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_move_right(t_mlx_datas *vars)
{
	if (player_can_move(vars, vars->play_pos.x + 1, vars->play_pos.y))
	{
		vars->play_pos.x++;
		vars->play_pos.right = 1;
		vars->moves.count++;
		vars->play_pos.look_right = 1;
	}
}

static void	check_move_left(t_mlx_datas *vars)
{
	if (player_can_move(vars, vars->play_pos.x - 1, vars->play_pos.y))
	{
		vars->play_pos.x--;
		vars->play_pos.left = 1;
		vars->moves.count++;
		vars->play_pos.look_right = 0;
	}
}

static void	check_move_up(t_mlx_datas *vars)
{
	if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y - 1))
	{
		vars->play_pos.y--;
		vars->play_pos.up = 1;
		vars->moves.count++;
	}
}

static void	check_move_down(t_mlx_datas *vars)
{
	if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y + 1))
	{
		vars->play_pos.y++;
		vars->play_pos.down = 1;
		vars->moves.count++;
	}
}

int	mov_key_hook(int keycode, t_mlx_datas *vars)
{
	if (keycode == 'd')
		check_move_right(vars);
	if (keycode == 'a')
		check_move_left(vars);
	if (keycode == 's')
		check_move_down(vars);
	if (keycode == 'w')
		check_move_up(vars);
	return (0);
}
