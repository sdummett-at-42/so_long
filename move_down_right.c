/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:14:26 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 05:02:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_first_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_down.down_0.img, width, height - 50);
	put_img(vars, vars->tearing.up16px.img, width, height - 66);
}

static void	render_second_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_down.down_1.img, width, height - 34);
	put_img(vars, vars->tearing.up33px.img, width, height - 66);
}

static void	render_third_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_down.down_2.img, width, height - 16);
	put_img(vars, vars->tearing.up50px.img, width, height - 66);
}

static void	render_last_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_down.down_3.img, width, height);
	put_img(vars, vars->p_right.right.img, width, height);
	vars->play_pos.down = 0;
	put_free_space(vars);
	put_ath(vars);
	vars->play_pos.is_moving = 0;
}

void	move_down_right(t_mlx_datas *vars)
{
	static int	i = 0;
	int			width;
	int			height;

	width = vars->play_pos.x * vars->width;
	height = vars->play_pos.y * vars->height;
	if (i == 0 )
		render_first_frame(vars, width, height);
	else if (i == 1)
		render_second_frame(vars, width, height);
	else if (i == 2)
		render_third_frame(vars, width, height);
	else if (i == 3)
		render_last_frame(vars, width, height);
	i++;
	if (i == 4)
		i = 0;
}
