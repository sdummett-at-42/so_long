/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:12:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 01:43:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_ath(t_mlx_datas *vars)
{
	char	*str;

	str = ft_itoa(vars->moves.count);
	put_img(vars, vars->ath.ath_2.img, vars->width, vars->moves.y);
	mlx_string_put(vars->mlx, vars->win, vars->width, \
		vars->moves.y + 37, 0xff8000, str);
	printf("Moves -> %d.\n", vars->moves.count);
	free(str);
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

void	move_down_right(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_down.down_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 50);
		put_img(vars, vars->anti_tearing.up16px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height - 66);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_down.down_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 34);
		put_img(vars, vars->anti_tearing.up33px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height - 66);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_down.down_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 16);
		put_img(vars, vars->anti_tearing.up50px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height - 66);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_down.down_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.down = 0;
		put_free_space(vars);
		put_ath(vars);
		vars->play_pos.is_moving = 0;
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_down_left(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_down.down_left_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 50);
		put_img(vars, vars->anti_tearing.up16px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height - 66);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_down.down_left_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 34);
		put_img(vars, vars->anti_tearing.up33px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height - 66);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_down.down_left_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 16);
		put_img(vars, vars->anti_tearing.up50px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height - 66);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_down.down_left_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_left.left.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.down = 0;
		put_free_space(vars);
		put_ath(vars);
		vars->play_pos.is_moving = 0;
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_up_right(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_down.down_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 50);
		put_img(vars, vars->anti_tearing.down16px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height + 66 + 50);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_down.down_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 33);
		put_img(vars, vars->anti_tearing.down33px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height + 66 + 33);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_down.down_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 16);
		put_img(vars, vars->anti_tearing.down50px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height + 66 + 16);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_down.down_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_right.right.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.up = 0;
		put_free_space(vars);
		put_ath(vars);
		vars->play_pos.is_moving = 0;
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_up_left(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_down.down_left_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 50);
		put_img(vars, vars->anti_tearing.down16px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height + 66 + 50);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_down.down_left_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 33);
		put_img(vars, vars->anti_tearing.down33px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height + 66 + 33);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_down.down_left_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 16);
		put_img(vars, vars->anti_tearing.down50px.img, \
			vars->play_pos.x * vars->width, \
			vars->play_pos.y * vars->height + 66 + 16);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_down.down_left_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_left.left.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.up = 0;
		put_free_space(vars);
		put_ath(vars);
		vars->play_pos.is_moving = 0;
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_left(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_left.left_0.img, \
					vars->play_pos.x * vars->width + 50, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->anti_tearing.right16px.img, \
			vars->play_pos.x * vars->width + 66 + 50, \
			vars->play_pos.y * vars->height);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_left.left_1.img, \
					vars->play_pos.x * vars->width + 33, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->anti_tearing.right33px.img, \
			vars->play_pos.x * vars->width + 66 + 33, \
			vars->play_pos.y * vars->height);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_left.left_2.img, \
					vars->play_pos.x * vars->width + 16, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->anti_tearing.right50px.img, \
			vars->play_pos.x * vars->width + 66 + 16, \
			vars->play_pos.y * vars->height);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_left.left_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_left.left.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.left = 0;
		put_free_space(vars);
		put_ath(vars);
		vars->play_pos.is_moving = 0;
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_right(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0)
	{
		put_img(vars, vars->p_right.right_0.img, \
					vars->play_pos.x * vars->width - 50, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->anti_tearing.left16px.img, \
			vars->play_pos.x * vars->width - 66, \
			vars->play_pos.y * vars->height);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_right.right_1.img, \
					vars->play_pos.x * vars->width - 33, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->anti_tearing.left33px.img, \
			vars->play_pos.x * vars->width - 66, \
			vars->play_pos.y * vars->height);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_right.right_2.img, \
					vars->play_pos.x * vars->width - 16, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->anti_tearing.left50px.img, \
			vars->play_pos.x * vars->width - 66, \
			vars->play_pos.y * vars->height);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_right.right_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_right.right.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.right = 0;
		put_free_space(vars);
		put_ath(vars);
		vars->play_pos.is_moving = 0;
	}
	i++;
	if (i == 4)
		i = 0;
}

void	win_animation(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0)
		put_img(vars, vars->p_win.win_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 1)
		put_img(vars, vars->p_win.win_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 2)
		put_img(vars, vars->p_win.win_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 3)
		put_img(vars, vars->p_win.win_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 4)
		put_img(vars, vars->p_win.win_4.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 5)
		put_img(vars, vars->p_win.win_5.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 6)
		put_img(vars, vars->p_win.win_6.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 7)
	{
		put_img(vars, vars->p_win.win_7.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, \
		vars->free_space.img, vars->play_pos.x * vars->width, \
		vars->play_pos.y * vars->height);
		vars->play_pos.won = 1;
	}
	i++;
}

void	lost_animation(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0)
		put_img(vars, vars->p_lost.lost_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 1)
		put_img(vars, vars->p_lost.lost_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	else if (i == 2)
	{
		put_img(vars, vars->p_lost.lost_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		mlx_loop_end (vars->mlx);
	}
	i++;
}

void	madara_atk_animation(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0)
		put_img(vars, vars->madara.atk_0.img, \
					vars->play_pos.last_x * vars->width, \
					vars->play_pos.last_y * vars->height);
	else if (i == 1)
		put_img(vars, vars->madara.atk_1.img, \
					vars->play_pos.last_x * vars->width, \
					vars->play_pos.last_y * vars->height);
	else if (i == 2)
	{
		put_img(vars, vars->madara.atk_2.img, \
					vars->play_pos.last_x * vars->width, \
					vars->play_pos.last_y * vars->height);
		vars->play_pos.lost = 1;
	}
	i++;
}

void	tobi_tp_animation(t_mlx_datas *vars)
{
	static int	i = 0;

	if (i == 0)
		put_img(vars, vars->tobi.exit_0.img, \
					vars->play_pos.last_x * vars->width, \
					vars->play_pos.last_y * vars->height);
	else if (i == 1)
		put_img(vars, vars->tobi.exit_1.img, \
					vars->play_pos.last_x * vars->width, \
					vars->play_pos.last_y * vars->height);
	else if (i == 2)
	{
		put_img(vars, vars->tobi.exit_2.img, \
					vars->play_pos.last_x * vars->width, \
					vars->play_pos.last_y * vars->height);
		mlx_loop_end (vars->mlx);
	}
	i++;
}
