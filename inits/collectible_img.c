/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:07:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:59:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	init_collectible_imgs_2(t_mlx_datas *vars)
{
	vars->collect_imgs.kunai_6.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_6.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_6.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_7.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_7.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_7.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_8.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_8.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_8.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_9.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_9.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_9.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_10.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_10.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_10.img, "Image reading has \
	failed.\n"))
		return (-1);
	return (0);
}

int	init_collectible_imgs(t_mlx_datas *vars)
{
	vars->collect_imgs.kunai_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_0.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_1.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_2.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_3.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_3.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_4.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_4.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_4.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_5.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/kunai_5.xpm", &vars->width, &vars->height);
	if (error_msg(vars->collect_imgs.kunai_5.img, "Image reading has failed.\n"))
		return (-1);
	return (init_collectible_imgs_2(vars));
}
