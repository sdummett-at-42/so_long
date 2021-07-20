/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:22:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 22:23:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_p_left_imgs_2(t_mlx_datas *vars)
{
	vars->p_left.left_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_left.left_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_mov_left_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_left.left_3.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_p_left_imgs(t_mlx_datas *vars)
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
	return (init_p_left_imgs_2(vars));
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
