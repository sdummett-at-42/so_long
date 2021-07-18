/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:12:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 13:17:30 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_free_space(t_mlx_datas *vars)
{
	if (vars->play_pos.last_x != vars->play_pos.x || vars->play_pos.last_y != \
	vars->play_pos.y)
	{
		put_img(vars, \
		vars->free_space.img, vars->play_pos.last_x * vars->width, \
		vars->play_pos.last_y * vars->height);
		vars->play_pos.last_x = vars->play_pos.x;
		vars->play_pos.last_y = vars->play_pos.y;
	}
}

void	move_down(t_mlx_datas *vars)
{
	static int i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_front.front_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 28);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_front.front_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 24);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_front.front_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 20);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_front.front_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 16);
	}
	else if (i == 4)
	{
		put_img(vars, vars->p_front.front_4.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 12);
	}
	else if (i == 5)
	{
		// put_img(vars, vars->p_front.front_5.img, \
	// 				vars->play_pos.x * vars->p_front.front_5.width, \
	// 				vars->play_pos.y * vars->p_front.front_5.height}
	put_img(vars, vars->p_front.front_6.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 8);
	}
	else if (i == 6)
	{
		put_img(vars, vars->p_front.front_7.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 4);
		put_img(vars, vars->p_front.front.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.down = 0;
		put_free_space(vars);
	}
	i++;
	if (i == 7)
		i = 0;
}

void	move_up(t_mlx_datas *vars)
{
	put_img(vars, vars->play_imgs.back.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	vars->play_pos.up = 0;
	put_free_space(vars);
}

void	move_left(t_mlx_datas *vars)
{
	put_img(vars, vars->play_imgs.left.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	vars->play_pos.left = 0;
	put_free_space(vars);
}

void	move_right(t_mlx_datas *vars)
{
	put_img(vars, vars->play_imgs.right.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
	vars->play_pos.right = 0;
	put_free_space(vars);
}