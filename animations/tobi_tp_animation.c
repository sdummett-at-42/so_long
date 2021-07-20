/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobi_tp_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:21:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:14:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
