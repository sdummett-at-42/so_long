/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:23:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 20:08:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int player_can_move(t_mlx_datas *vars, int x, int y)
{
	if (vars->play_pos.won == 0 && vars->play_pos.is_moving == 0 && \
	vars->play_pos.lost == 0)
	{
		if (vars->map[y][x] == 'C')
		{
			vars->map_datas.collectible--;
			vars->map[y][x] = '0';
		}
		else if (vars->map[y][x] == 'M')
		{
			vars->play_pos.lost = 2;
			vars->play_pos.last_x = x;
			vars->play_pos.last_y = y;
			return (0);
		}
		else if (vars->map[y][x] == 'E' && vars->map_datas.collectible == 0)
		{
			vars->play_pos.won = 2;
			vars->play_pos.last_x = x;
			vars->play_pos.last_y = y;
			return (0);
		}
		else if (vars->map[y][x] == '1' || vars->map[y][x] == 'E')
			return (0);
		vars->play_pos.is_moving = 1;
		return (1);
	}
	return (0);
}

int mov_key_hook(int keycode, t_mlx_datas *vars)
{
	if (keycode == 'd')
	{
		if (player_can_move(vars, vars->play_pos.x + 1, vars->play_pos.y))
		{
			vars->play_pos.x++;
			vars->play_pos.right = 1;
			vars->moves++;
		}
	}
	if (keycode == 'a')
	{
		if (player_can_move(vars, vars->play_pos.x - 1, vars->play_pos.y))
		{
			vars->play_pos.x--;
			vars->play_pos.left = 1;
			vars->moves++;
		}
	}
	if (keycode == 's')
	{
		if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y + 1))
		{
			vars->play_pos.y++;
			vars->play_pos.down = 1;
			vars->moves++;
		}
	}
	if (keycode == 'w')
	{
		if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y - 1))
		{
			vars->play_pos.y--;
			vars->play_pos.up = 1;
			vars->moves++;
		}
	}
	printf("moves : %d\n", vars->moves); // /!\ PRINTF !
	return (0);
}