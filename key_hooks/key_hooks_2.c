/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:37:15 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:59:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	player_won(t_mlx_datas *vars, int x, int y)
{
	vars->play_pos.lost = 2;
	vars->play_pos.last_x = x;
	vars->play_pos.last_y = y;
	return (0);
}

static int	player_lost(t_mlx_datas *vars, int x, int y)
{
	vars->play_pos.won = 2;
	vars->play_pos.last_x = x;
	vars->play_pos.last_y = y;
	return (0);
}
////// DEBUGG
void print_map(t_mlx_datas *vars)
{
	int y;
	int x;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			write(1, &(vars->map[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
/////////////

int	player_can_move(t_mlx_datas *vars, int x, int y)
{
	if (vars->play_pos.won == 0 && vars->play_pos.is_moving == 0 && \
	vars->play_pos.lost == 0)
	{
		if (vars->map[y][x] == 'C')
		{
			vars->map_datas.collectible--;
			vars->map[y][x] = 'P';
			vars->map[vars->play_pos.y][vars->play_pos.x] = '0';
			//print_map(vars);
		}
		else if (vars->map[y][x] == 'M')
			return (player_won(vars, x, y));
		else if (vars->map[y][x] == 'E' && vars->map_datas.collectible == 0)
			return (player_lost(vars, x, y));
		else if (vars->map[y][x] == '1' || vars->map[y][x] == 'E')
			return (0);
		else
		{
			vars->map[vars->play_pos.y][vars->play_pos.x] = '0';
			vars->map[y][x] = 'P';
			vars->play_pos.is_moving = 1;
		}
		return (1);
	}
	return (0);
}
