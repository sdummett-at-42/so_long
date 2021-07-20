/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:02:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 02:09:20 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Initialize player win animation images.
*/

static int	init_p_win_imgs_2(t_mlx_datas *vars)
{
	vars->p_win.win_4.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_4.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_4.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_win.win_5.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_5.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_5.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_win.win_6.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_6.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_6.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_win.win_7.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_7.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_7.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_p_win_imgs(t_mlx_datas *vars)
{
	vars->p_win.win_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_win.win_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_win.win_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_win.win_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_win_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_win.win_3.img, "Image reading has failed.\n"))
		return (-1);
	return (init_p_win_imgs_2(vars));
}

/*
** Initialize player lost animation images.
*/
int	init_p_lost_imgs(t_mlx_datas *vars)
{
	vars->p_lost.lost_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_lost_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_lost.lost_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_lost.lost_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_lost_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_lost.lost_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_lost.lost_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_lost_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_lost.lost_2.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

/*
** Initialize Tobi images.
*/

int	init_tobi_imgs(t_mlx_datas *vars)
{
	vars->tobi.stand.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/tobi.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tobi.stand.img, "Image reading has failed.\n"))
		return (-1);
	vars->tobi.exit_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/tobi_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tobi.exit_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->tobi.exit_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/tobi_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tobi.exit_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->tobi.exit_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/tobi_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tobi.exit_2.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

/*
** Initialize Madara images.
*/

int	init_madara_imgs(t_mlx_datas *vars)
{
	vars->madara.stand.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/m_stand.xpm", &vars->width, &vars->height);
	if (error_msg(vars->madara.stand.img, "Image reading has failed.\n"))
		return (-1);
	vars->madara.atk_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/m_atk_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->madara.atk_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->madara.atk_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/m_atk_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->madara.atk_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->madara.atk_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/m_atk_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->madara.atk_2.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}
