/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:12:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/26 21:07:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_sprites(t_mlx_datas *vars, char c, int x, int y)
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

void	put_player(t_mlx_datas *vars, int x, int y)
{
	if (vars->play_pos.look_right == 1)
		put_img(vars, vars->p_right.right.img, x, y);
	else
		put_img(vars, vars->p_left.left.img, x, y);
}

static void	print_moves(t_mlx_datas *vars, int *last_move_value)
{
	if (*last_move_value != vars->moves.count)
	{
		printf("Moves -> %d.\n", vars->moves.count);
		*last_move_value = vars->moves.count;
	}
}

void	put_ath(t_mlx_datas *vars)
{
	int			i;
	char		*str;
	static int	last_move_value = 0;

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
				print_moves(vars, &last_move_value);
			}
		}
		i++;
	}
}

void	put_free_space(t_mlx_datas *vars)
{
	if (vars->play_pos.last_x != vars->play_pos.x || vars->play_pos.last_y != \
	vars->play_pos.y)
	{
		put_img(vars, \
		vars->free_space.img, vars->play_pos.last_x * vars->width, \
		vars->play_pos.last_y * vars->height);
		vars->play_pos.last_x = vars->play_pos.x;
		vars->play_pos.last_y = vars->play_pos.y;
	}
}
