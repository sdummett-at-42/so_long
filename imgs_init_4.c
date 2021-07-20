/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:08:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 02:16:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Initialize anti-screen tearing images.
*/
static int	init_anti_screentearing_2(t_mlx_datas *vars)
{
	vars->tearing.up16px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_16px_up.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.up16px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.up33px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_33px_up.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.up33px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.up50px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_50px_up.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.up50px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.down16px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_16px_down.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.down16px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.down33px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_33px_down.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.down33px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.down50px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_50px_down.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.down50px.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_anti_screentearing(t_mlx_datas *vars)
{
	vars->tearing.left16px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_16px_left.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.left16px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.left33px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_33px_left.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.left33px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.left50px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_50px_left.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.left50px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.right16px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_16px_right.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.right16px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.right33px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_33px_right.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.right33px.img, "Image reading has failed.\n"))
		return (-1);
	vars->tearing.right50px.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground_50px_right.xpm", &vars->width, &vars->height);
	if (error_msg(vars->tearing.right50px.img, "Image reading has failed.\n"))
		return (-1);
	return (init_anti_screentearing_2(vars));
}

int	init_ground_imgs(t_mlx_datas *vars)
{
	vars->free_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground.xpm", &vars->width, &vars->height);
	if (error_msg(vars->free_space.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_wall_imgs(t_mlx_datas *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/rock.xpm", &vars->width, &vars->height);
	if (error_msg(vars->wall.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_ath(t_mlx_datas *vars)
{
	vars->ath.ath_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/mugshot_right.xpm", &vars->width, &vars->height);
	if (error_msg(vars->ath.ath_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->ath.ath_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/pepe_naruto.xpm", &vars->width, &vars->height);
	if (error_msg(vars->ath.ath_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->ath.ath_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/black_img.xpm", &vars->width, &vars->height);
	if (error_msg(vars->ath.ath_2.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}
