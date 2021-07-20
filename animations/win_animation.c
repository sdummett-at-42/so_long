/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:19:07 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:14:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_last_frame(t_mlx_datas *vars, int width, int height)
{
	put_img(vars, vars->p_win.win_7.img, width, height);
	put_img(vars, vars->free_space.img, width, height);
	vars->play_pos.won = 1;
}

void	win_animation(t_mlx_datas *vars)
{
	static int	i = 0;
	int			width;
	int			height;

	width = vars->play_pos.x * vars->width;
	height = vars->play_pos.y * vars->height;
	if (i == 0)
		put_img(vars, vars->p_win.win_0.img, width, height);
	else if (i == 1)
		put_img(vars, vars->p_win.win_1.img, width, height);
	else if (i == 2)
		put_img(vars, vars->p_win.win_2.img, width, height);
	else if (i == 3)
		put_img(vars, vars->p_win.win_3.img, width, height);
	else if (i == 4)
		put_img(vars, vars->p_win.win_4.img, width, height);
	else if (i == 5)
		put_img(vars, vars->p_win.win_5.img, width, height);
	else if (i == 6)
		put_img(vars, vars->p_win.win_6.img, width, height);
	else if (i == 7)
		render_last_frame(vars, width, height);
	i++;
}
