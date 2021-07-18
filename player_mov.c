/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:12:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 17:19:21 by sdummett         ###   ########.fr       */
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
		put_img(vars, vars->p_down.front_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 50);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_down.front_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 33);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_down.front_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height - 16);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_down.front_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.down = 0;
		put_free_space(vars);
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_up(t_mlx_datas *vars)
{
	static int i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_down.front_0.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 50);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_down.front_1.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 33);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_down.front_2.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height + 16);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_down.front_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.up = 0;
		put_free_space(vars);
	}
	i++;
	if (i == 4)
		i = 0;
}

// void	move_left(t_mlx_datas *vars)
// {
// 	put_img(vars, vars->play_imgs.left.img, \
// 					vars->play_pos.x * vars->width, \
// 					vars->play_pos.y * vars->height);
// 	vars->play_pos.left = 0;
// 	put_free_space(vars);
// }
void	move_left(t_mlx_datas *vars)
{
	static int i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_left.left_0.img, \
					vars->play_pos.x * vars->width + 50, \
					vars->play_pos.y * vars->height);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_left.left_1.img, \
					vars->play_pos.x * vars->width + 33, \
					vars->play_pos.y * vars->height);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_left.left_2.img, \
					vars->play_pos.x * vars->width + 16, \
					vars->play_pos.y * vars->height);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_left.left_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_left.left.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.left = 0;
		put_free_space(vars);
	}
	i++;
	if (i == 4)
		i = 0;
}

void	move_right(t_mlx_datas *vars)
{
	static int i = 0;

	if (i == 0 )
	{
		put_img(vars, vars->p_right.right_0.img, \
					vars->play_pos.x * vars->width - 50, \
					vars->play_pos.y * vars->height);
	}
	else if (i == 1)
	{
		put_img(vars, vars->p_right.right_1.img, \
					vars->play_pos.x * vars->width - 33, \
					vars->play_pos.y * vars->height);
	}
	else if (i == 2)
	{
		put_img(vars, vars->p_right.right_2.img, \
					vars->play_pos.x * vars->width - 16, \
					vars->play_pos.y * vars->height);
	}
	else if (i == 3)
	{
		put_img(vars, vars->p_right.right_3.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		put_img(vars, vars->p_right.right.img, \
					vars->play_pos.x * vars->width, \
					vars->play_pos.y * vars->height);
		vars->play_pos.right = 0;
		put_free_space(vars);
	}
	i++;
	if (i == 4)
		i = 0;
}