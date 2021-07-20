/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:44:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 22:12:24 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_img_datas_2(t_mlx_datas *vars)
{
	if (init_p_right_imgs(vars) == -1)
		return (-1);
	if (init_p_left_imgs(vars) == -1)
		return (-1);
	if (init_p_win_imgs(vars) == -1)
		return (-1);
	if (init_p_lost_imgs(vars) == -1)
		return (-1);
	if (init_madara_imgs(vars) == -1)
		return (-1);
	if (init_tobi_imgs(vars) == -1)
		return (-1);
	return (0);
}

static int	init_img_datas(t_mlx_datas *vars)
{
	if (init_ath(vars) == -1)
		return (-1);
	if (init_ground_imgs(vars) == -1)
		return (-1);
	if (init_wall_imgs(vars) == -1)
		return (-1);
	if (init_anti_screentearing(vars) == -1)
		return (-1);
	if (init_collectible_imgs(vars) == -1)
		return (-1);
	if (init_p_up_right_imgs(vars) == -1)
		return (-1);
	if (init_p_up_left_imgs(vars) == -1)
		return (-1);
	if (init_p_down_right_imgs(vars) == -1)
		return (-1);
	if (init_p_down_left_imgs(vars) == -1)
		return (-1);
	return (init_img_datas_2(vars));
}

int	init_window(t_mlx_datas *vars)
{
	vars->win_size_x = vars->map_datas.width * vars->width;
	vars->win_size_y = vars->map_datas.height * vars->height + vars->height;
	vars->win = mlx_new_window(vars->mlx, vars->win_size_x, \
			vars->win_size_y, "so_long");
	vars->moves.count = 0;
	vars->moves.x = vars->map_datas.width * vars->width;
	vars->moves.y = vars->map_datas.height * \
		vars->height;
	vars->play_pos.look_right = 0;
	if (error_msg(vars->win, "Opening a new window has failed.\n"))
		return (-1);
	return (0);
}

int	init_mlx_datas_struct(t_mlx_datas *vars)
{
	init_all_vars(vars);
	vars->mlx = mlx_init();
	if (error_msg(vars->mlx, "mlx_init has failed.\n"))
		return (-1);
	if (init_img_datas(vars) == -1)
		return (-1);
	if (init_window(vars) == -1)
		return (-1);
	return (0);
}

void	init_map_datas_struct(t_map_datas *map)
{
	map->width = 0;
	map->height = 0;
	map->collectible = 0;
	map->player = 0;
	map->exit = 0;
}
