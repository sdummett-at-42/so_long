/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:57:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 02:23:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_p_up_down_right_imgs(t_mlx_datas *vars)
{
	vars->p_down.down_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_p_up_down_left_imgs(t_mlx_datas *vars)
{
	vars->p_down.down_left_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_left_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_left_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_left_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

static int	init_p_right_imgs_2(t_mlx_datas *vars)
{
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

int	init_p_right_imgs(t_mlx_datas *vars)
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
	return (init_p_right_imgs_2(vars));
}
