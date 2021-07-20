/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:19:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:13:40 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
