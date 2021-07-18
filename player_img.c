/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:57:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 18:43:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_p_down_imgs(t_mlx_datas *vars)
{
	vars->p_down.down.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_stand_left.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_0.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_1.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_2.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_3.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int init_p_right_imgs(t_mlx_datas *vars)
{
	vars->p_right.right.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_stand_right.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_right.right_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_right_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_right.right_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_right_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_right.right_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_right_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_right.right_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_right_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right_3.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_right.right_4.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_right_4.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right_4.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_right.right_5.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_right_5.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_right.right_5.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int init_p_left_imgs(t_mlx_datas *vars)
{
	vars->p_left.left.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_stand_left.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_3.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_4.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_4.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_4.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_5.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_5.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_5.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int init_p_win_imgs(t_mlx_datas *vars)
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