/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:42:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:59:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_player_pos(t_mlx_datas *vars, int i, int j)
{
	vars->play_pos.x = j;
	vars->play_pos.y = i;
	vars->play_pos.last_x = j;
	vars->play_pos.last_y = i;
	vars->play_pos.up = 0;
	vars->play_pos.down = 0;
	vars->play_pos.left = 0;
	vars->play_pos.right = 0;
	vars->play_pos.won = 0;
	vars->play_pos.lost = 0;
	vars->play_pos.is_moving = 0;
	vars->play_pos.look_right = 1;
}

void	init_map_ath(t_mlx_datas *vars)
{
	int		i;
	char	*str;

	i = 1;
	while (i * vars->width < vars->win_size_x)
	{
		if (i == 1)
			put_img(vars, vars->ath.ath_0.img, 0, vars->moves.y);
		else
		{
			put_img(vars, vars->ath.ath_1.img, i * vars->width, vars->moves.y);
			if (i == 2)
			{
				str = ft_itoa(vars->moves.count);
				mlx_string_put(vars->mlx, vars->win, vars->width, \
					vars->moves.y + 37, 0xff8000, str);
				free(str);
			}
		}
		i++;
	}
}

void	init_map(t_mlx_datas *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (vars->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == 'P')
			{
				init_player_pos(vars, i, j);
				return ;
			}
			x = x + vars->height;
			j++;
		}
		y = y + vars->width;
		i++;
	}
}
