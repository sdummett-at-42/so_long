/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:44:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 00:24:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int init_mov_imgs_struct(t_mlx_datas*vars)
{
	vars->mov_imgs.front_0.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_0.xpm", &vars->mov_imgs.front_0.width, &vars->mov_imgs.front_0.height);
	if (error_msg(vars->mov_imgs.front_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->mov_imgs.front_1.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_1.xpm", &vars->mov_imgs.front_1.width, &vars->mov_imgs.front_1.height);
	if (error_msg(vars->mov_imgs.front_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->mov_imgs.front_2.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_2.xpm", &vars->mov_imgs.front_2.width, &vars->mov_imgs.front_2.height);
	if (error_msg(vars->mov_imgs.front_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->mov_imgs.front_3.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_3.xpm", &vars->mov_imgs.front_3.width, &vars->mov_imgs.front_3.height);
	if (error_msg(vars->mov_imgs.front_3.img, "Image reading has failed.\n"))
		return (-1);
	vars->mov_imgs.front_4.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_4.xpm", &vars->mov_imgs.front_4.width, &vars->mov_imgs.front_4.height);
	if (error_msg(vars->mov_imgs.front_4.img, "Image reading has failed.\n"))
		return (-1);
	// vars->mov_imgs.front_5.img= mlx_xpm_file_to_image(vars->mlx, \
	// "tileset/run_front_5.xpm", &vars->mov_imgs.front_5.width, &vars->mov_imgs.front_5.height);
	// if (error_msg(vars->mov_imgs.front_5.img, "Image reading has failed.\n"))
	// 	return (-1);
	vars->mov_imgs.front_6.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_6.xpm", &vars->mov_imgs.front_6.width, &vars->mov_imgs.front_6.height);
	if (error_msg(vars->mov_imgs.front_6.img, "Image reading has failed.\n"))
		return (-1);
	vars->mov_imgs.front_7.img= mlx_xpm_file_to_image(vars->mlx, \
	"tileset/run_front_7.xpm", &vars->mov_imgs.front_7.width, &vars->mov_imgs.front_7.height);
	if (error_msg(vars->mov_imgs.front_7.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

static int	init_player_img_struct(t_mlx_datas *vars)
{
	vars->play_imgs.front.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/ngf.xpm", &vars->play_imgs.front.width, &vars->play_imgs.front.height);
	if (error_msg(vars->play_imgs.front.img, "Image reading has failed.\n"))
		return (-1);
	vars->play_imgs.back.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/ngb.xpm", &vars->play_imgs.back.width, &vars->play_imgs.back.height);
	if (error_msg(vars->play_imgs.back.img, "Image reading has failed.\n"))
		return (-1);
	vars->play_imgs.left.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/ngl.xpm", &vars->play_imgs.left.width, &vars->play_imgs.left.height);
	if (error_msg(vars->play_imgs.left.img, "Image reading has failed.\n"))
		return (-1);
	vars->play_imgs.right.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/ngr.xpm", &vars->play_imgs.right.width, &vars->play_imgs.right.height);
	if (error_msg(vars->play_imgs.right.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

static int init_collectible_img_struct(t_mlx_datas *vars)
{
	vars->collect_imgs.kunai_0.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_0.xpm", &vars->collect_imgs.kunai_0.width, &vars->collect_imgs.kunai_0.height);
	if (error_msg(vars->collect_imgs.kunai_0.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_1.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_1.xpm", &vars->collect_imgs.kunai_1.width, &vars->collect_imgs.kunai_1.height);
	if (error_msg(vars->collect_imgs.kunai_1.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_2.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_2.xpm", &vars->collect_imgs.kunai_2.width, &vars->collect_imgs.kunai_2.height);
	if (error_msg(vars->collect_imgs.kunai_2.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_3.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_3.xpm", &vars->collect_imgs.kunai_3.width, &vars->collect_imgs.kunai_3.height);
	if (error_msg(vars->collect_imgs.kunai_3.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_4.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_4.xpm", &vars->collect_imgs.kunai_4.width, &vars->collect_imgs.kunai_4.height);
	if (error_msg(vars->collect_imgs.kunai_4.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_5.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_5.xpm", &vars->collect_imgs.kunai_5.width, &vars->collect_imgs.kunai_5.height);
	if (error_msg(vars->collect_imgs.kunai_5.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_6.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_6.xpm", &vars->collect_imgs.kunai_6.width, &vars->collect_imgs.kunai_6.height);
	if (error_msg(vars->collect_imgs.kunai_6.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_7.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_7.xpm", &vars->collect_imgs.kunai_7.width, &vars->collect_imgs.kunai_7.height);
	if (error_msg(vars->collect_imgs.kunai_7.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_8.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_8.xpm", &vars->collect_imgs.kunai_8.width, &vars->collect_imgs.kunai_8.height);
	if (error_msg(vars->collect_imgs.kunai_8.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_9.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_9.xpm", &vars->collect_imgs.kunai_9.width, &vars->collect_imgs.kunai_9.height);
	if (error_msg(vars->collect_imgs.kunai_9.img, "Image reading has failed.\n"))
		return (-1);
	vars->collect_imgs.kunai_10.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/kunai_10.xpm", &vars->collect_imgs.kunai_10.width, &vars->collect_imgs.kunai_10.height);
	if (error_msg(vars->collect_imgs.kunai_10.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

static int	init_img_datas_struct(t_mlx_datas *vars)
{
	vars->free_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/ground_32px.xpm", &vars->free_space.width, &vars->free_space.height);
	vars->free_space.x = 0;
	vars->free_space.y = 0;
	if (error_msg(vars->free_space.img, "Image reading has failed.\n"))
		return (-1);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/rock_grounded_32px.xpm", &vars->wall.width, &vars->wall.height);
	vars->wall.x = 0;
	vars->wall.y = 0;
	if (error_msg(vars->wall.img, "Image reading has failed.\n"))
		return (-1);
	if (init_collectible_img_struct(vars) == -1)
		return (-1);
	if (init_player_img_struct(vars) == -1)
		return (-1);
	if (init_mov_imgs_struct(vars) == -1)
		return (-1);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, \
	"tileset/parchemin32px.xpm", &vars->exit.width, &vars->exit.height);
	vars->exit.x = 0;
	vars->exit.y = 0;
	if (error_msg(vars->exit.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int	init_mlx_datas_struct(t_mlx_datas *vars)
{
	vars->mlx = mlx_init();
	if (error_msg(vars->mlx, "mlx_init has failed.\n"))
		return (0);
	vars->moves = 0;
	if (init_img_datas_struct(vars) == -1)
		return (-1);
	vars->win_size_x = vars->free_space.width * vars->map_datas.width;
	vars->win_size_y = vars->free_space.height * vars->map_datas.height;
	vars->win = mlx_new_window(vars->mlx, vars->win_size_x, \
			vars->win_size_y, "so_long");
	if (error_msg(vars->win, "Opening a new window has failed.\n"))
		return (0);
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