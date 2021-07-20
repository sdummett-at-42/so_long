/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:12:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 04:21:22 by sdummett         ###   ########.fr       */
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
