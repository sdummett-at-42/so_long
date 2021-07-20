/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:57:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 22:23:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_p_down_right_imgs(t_mlx_datas *vars)
{
	vars->p_down.down_right_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_right_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_right_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_right_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_right_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_right_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_right_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_right_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_right_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_right_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_right_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_right_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_p_down_left_imgs(t_mlx_datas *vars)
{
	vars->p_down.down_left_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_left_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_left_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_left_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_left_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_left_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_down.down_left_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_down_left_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_down.down_left_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_p_up_right_imgs(t_mlx_datas *vars)
{
	vars->p_up.up_right_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_right_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_right_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_up.up_right_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_right_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_right_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_up.up_right_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_right_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_right_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_up.up_right_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_right_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_right_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_p_up_left_imgs(t_mlx_datas *vars)
{
	vars->p_up.up_left_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_left_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_up.up_left_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_left_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_up.up_left_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_left_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_up.up_left_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_up_left_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_up.up_left_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}
