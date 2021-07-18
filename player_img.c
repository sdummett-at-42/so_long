/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:57:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 13:08:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_p_front_struct(t_mlx_datas*vars)
{
	vars->p_front.front.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/p_down.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_front.front_0.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_front.front_1.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_front.front_2.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_front.front_3.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_3.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_front.front_4.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_4.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_4.img, "Image reading has failed.\n"))
		return (-1);
	// vars->p_front.front_5.img= mlx_xpm_file_to_image(vars->mlx, \
	// "sprites/run_front_5.xpm", &vars->p_front.front_5.width, &vars->p_front.front_5.height);
	// if (error_msg(vars->p_front.front_5.img, "Image reading has failed.\n"))
	// 	return (-1);
	vars->p_front.front_6.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_6.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_6.img, "Image reading has failed.\n"))
		return (-1);
	vars->p_front.front_7.img= mlx_xpm_file_to_image(vars->mlx, \
	"sprites/run_front_7.xpm", &vars->width, &vars->height);
	if (error_msg(vars->p_front.front_7.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}