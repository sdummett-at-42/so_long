/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:18:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:13:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_first_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_left.left_0.img, width + 50, height);
	put_img(vars, vars->tearing.right16px.img, width + 66 + 50, height);
}

static void	render_second_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_left.left_1.img, width + 33, height);
	put_img(vars, vars->tearing.right33px.img, width + 66 + 33, height);
}

static void	render_third_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_left.left_2.img, width + 16, height);
	put_img(vars, vars->tearing.right50px.img, width + 66 + 16, height);
}

static void	render_last_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_left.left_3.img, width, height);
	put_img(vars, vars->p_left.left.img, width, height);
	vars->play_pos.left = 0;
	put_free_space(vars);
	put_ath(vars);
	vars->play_pos.is_moving = 0;
}

void	move_left(t_mlx_datas *vars)
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
