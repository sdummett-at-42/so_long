/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:42:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 16:52:44 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_put_exit(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->exit.img, x, y);
}

void	init_put_collectible(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->collect_imgs.kunai_0.img, x, y);
}

void	init_put_player(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->p_down.front.img, x, y);
}

void	init_put_free_space(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->free_space.img, x, y);
}

void	init_put_wall(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->wall.img, x, y);
}

void	init_map(t_mlx_datas *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (vars->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == '1')
				init_put_wall(vars, x, y);
			else if (vars->map[i][j] == '0')
				init_put_free_space(vars, x, y);
			else if (vars->map[i][j] == 'C')
				init_put_collectible(vars, x, y);
			else if (vars->map[i][j] == 'E')
				init_put_exit(vars, x, y);
			else if (vars->map[i][j] == 'P')
			{
				vars->play_pos.x = j;
				vars->play_pos.y = i;
				vars->play_pos.last_x = j;
				vars->play_pos.last_y = i;
				vars->play_pos.up = 0;
				vars->play_pos.down = 0;
				vars->play_pos.left = 0;
				vars->play_pos.right= 0;
				init_put_player(vars, x, y);
			}
			x = x + vars->height;
			j++;
		}
		y = y + vars->width;
		i++;
	}
}
