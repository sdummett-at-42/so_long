/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   madara_atk_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:20:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:13:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
