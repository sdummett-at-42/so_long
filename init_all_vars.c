/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:54:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 02:18:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_all_vars_2(t_mlx_datas *vars)
{
	vars->tearing.up33px.img = NULL;
	vars->tearing.up50px.img = NULL;
	vars->tearing.down16px.img = NULL;
	vars->tearing.down33px.img = NULL;
	vars->tearing.down50px.img = NULL;
	vars->free_space.img = NULL;
	vars->wall.img = NULL;
	vars->ath.ath_0.img = NULL;
	vars->ath.ath_1.img = NULL;
	vars->ath.ath_2.img = NULL;
	vars->collect_imgs.kunai_0.img = NULL;
	vars->collect_imgs.kunai_1.img = NULL;
	vars->collect_imgs.kunai_2.img = NULL;
	vars->collect_imgs.kunai_3.img = NULL;
	vars->collect_imgs.kunai_4.img = NULL;
	vars->collect_imgs.kunai_5.img = NULL;
	vars->collect_imgs.kunai_6.img = NULL;
	vars->collect_imgs.kunai_7.img = NULL;
	vars->collect_imgs.kunai_8.img = NULL;
	vars->collect_imgs.kunai_9.img = NULL;
	vars->collect_imgs.kunai_10.img = NULL;
}

static void	init_all_vars_1(t_mlx_datas *vars)
{
	vars->p_win.win_2.img = NULL;
	vars->p_win.win_3.img = NULL;
	vars->p_win.win_4.img = NULL;
	vars->p_win.win_5.img = NULL;
	vars->p_win.win_6.img = NULL;
	vars->p_win.win_7.img = NULL;
	vars->p_lost.lost_0.img = NULL;
	vars->p_lost.lost_1.img = NULL;
	vars->p_lost.lost_2.img = NULL;
	vars->tobi.stand.img = NULL;
	vars->tobi.exit_0.img = NULL;
	vars->tobi.exit_1.img = NULL;
	vars->tobi.exit_2.img = NULL;
	vars->madara.stand.img = NULL;
	vars->madara.atk_0.img = NULL;
	vars->madara.atk_1.img = NULL;
	vars->madara.atk_2.img = NULL;
	vars->tearing.left16px.img = NULL;
	vars->tearing.left33px.img = NULL;
	vars->tearing.left50px.img = NULL;
	vars->tearing.right16px.img = NULL;
	vars->tearing.right33px.img = NULL;
	vars->tearing.right50px.img = NULL;
	vars->tearing.up16px.img = NULL;
	init_all_vars_2(vars);
}

void	init_all_vars(t_mlx_datas *vars)
{
	vars->p_down.down_0.img = NULL;
	vars->p_down.down_1.img = NULL;
	vars->p_down.down_2.img = NULL;
	vars->p_down.down_3.img = NULL;
	vars->p_down.down_left_0.img = NULL;
	vars->p_down.down_left_1.img = NULL;
	vars->p_down.down_left_2.img = NULL;
	vars->p_down.down_left_3.img = NULL;
	vars->p_right.right.img = NULL;
	vars->p_right.right_0.img = NULL;
	vars->p_right.right_1.img = NULL;
	vars->p_right.right_2.img = NULL;
	vars->p_right.right_3.img = NULL;
	vars->p_right.right_4.img = NULL;
	vars->p_right.right_5.img = NULL;
	vars->p_left.left.img = NULL;
	vars->p_left.left_0.img = NULL;
	vars->p_left.left_1.img = NULL;
	vars->p_left.left_2.img = NULL;
	vars->p_left.left_3.img = NULL;
	vars->p_left.left_4.img = NULL;
	vars->p_left.left_5.img = NULL;
	vars->p_win.win_0.img = NULL;
	vars->p_win.win_1.img = NULL;
	init_all_vars_1(vars);
}
