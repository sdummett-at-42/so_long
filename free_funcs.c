/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:53:12 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 00:34:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map_buffer(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	return (-1);
}

void	free_all_vars(t_mlx_datas *vars)
{
	free_map_buffer(vars->map);
	mlx_destroy_image(vars->mlx, vars->p_down.down_0.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_1.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_2.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_3.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_left_0.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_left_1.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_left_2.img);
	mlx_destroy_image(vars->mlx, vars->p_down.down_left_3.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right_0.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right_1.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right_2.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right_3.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right_4.img);
	mlx_destroy_image(vars->mlx, vars->p_right.right_5.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left_0.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left_1.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left_2.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left_3.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left_4.img);
	mlx_destroy_image(vars->mlx, vars->p_left.left_5.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_0.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_1.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_2.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_3.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_4.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_5.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_6.img);
	mlx_destroy_image(vars->mlx, vars->p_win.win_7.img);
	mlx_destroy_image(vars->mlx, vars->p_lost.lost_0.img);
	mlx_destroy_image(vars->mlx, vars->p_lost.lost_1.img);
	mlx_destroy_image(vars->mlx, vars->p_lost.lost_2.img);
	mlx_destroy_image(vars->mlx, vars->tobi.stand.img);
	mlx_destroy_image(vars->mlx, vars->tobi.exit_0.img);
	mlx_destroy_image(vars->mlx, vars->tobi.exit_1.img);
	mlx_destroy_image(vars->mlx, vars->tobi.exit_2.img);
	mlx_destroy_image(vars->mlx, vars->madara.stand.img);
	mlx_destroy_image(vars->mlx, vars->madara.atk_0.img);
	mlx_destroy_image(vars->mlx, vars->madara.atk_1.img);
	mlx_destroy_image(vars->mlx, vars->madara.atk_2.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.left16px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.left33px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.left50px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.right16px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.right33px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.right50px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.up16px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.up33px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.up50px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.down16px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.down33px.img);
	mlx_destroy_image(vars->mlx, vars->anti_tearing.down50px.img);
	mlx_destroy_image(vars->mlx, vars->free_space.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->ath.ath_0.img);
	mlx_destroy_image(vars->mlx, vars->ath.ath_1.img);
	mlx_destroy_image(vars->mlx, vars->ath.ath_2.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_0.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_1.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_2.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_3.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_4.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_5.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_6.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_7.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_8.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_9.img);
	mlx_destroy_image(vars->mlx, vars->collect_imgs.kunai_10.img);
}
