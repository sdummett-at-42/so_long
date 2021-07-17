/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:49:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/17 21:13:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tmp(t_mlx_datas *vars)
{
	vars->free_space.x = 0;
	vars->free_space.y = 0;
	vars->wall.x = 0;
	vars->wall.y = 0;
	vars->collectible.x = 0;
	vars->collectible.y = 0;
	vars->player.x = 0;
	vars->player.y = 0;
	vars->exit.x = 0;
	vars->exit.y = 0;
}

void	put_free_space(t_mlx_datas *vars)
{
	if (vars->play_pos.last_x != vars->play_pos.x || vars->play_pos.last_y != \
	vars->play_pos.y)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->free_space.img, vars->play_pos.last_x * vars->free_space.width, \
		vars->play_pos.last_y * vars->free_space.height);
		vars->play_pos.last_x = vars->play_pos.x;
		vars->play_pos.last_y = vars->play_pos.y;
	}
}

int	player_can_move(t_mlx_datas *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		vars->map_datas.collectible--;
		vars->map[y][x] = '0';
	}
	else if (vars->map[y][x] == 'E' && vars->map_datas.collectible == 0)
	{
		/*
		** Quit the game.
		*/
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	else if (vars->map[y][x] == '1' || vars->map[y][x] == 'E')
		return (0);
	return (1);
}

void	move_up(t_mlx_datas *vars)
{
	vars->play_pos.y--;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_imgs.back.img, \
					vars->play_pos.x * vars->play_imgs.back.width, \
					vars->play_pos.y * vars->play_imgs.back.height);
}

void	move_down(t_mlx_datas *vars)
{
	vars->play_pos.y++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_imgs.front.img, \
					vars->play_pos.x * vars->play_imgs.front.width, \
					vars->play_pos.y * vars->play_imgs.front.height);
}

void	move_left(t_mlx_datas *vars)
{
	vars->play_pos.x--;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_imgs.left.img, \
					vars->play_pos.x * vars->play_imgs.left.width, \
					vars->play_pos.y * vars->play_imgs.left.height);
}

void	move_right(t_mlx_datas *vars)
{
	vars->play_pos.x++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_imgs.right.img, \
					vars->play_pos.x * vars->play_imgs.right.width, \
					vars->play_pos.y * vars->play_imgs.right.height);
}

int	mov_key_hook(int keycode, t_mlx_datas *vars)
{
	if (keycode == 'd')
	{
		if (player_can_move(vars, vars->play_pos.x + 1, vars->play_pos.y))
		{
			move_right(vars);
			vars->moves++;
		}
	}
	if (keycode == 'a')
	{
		if (player_can_move(vars, vars->play_pos.x - 1, vars->play_pos.y))
		{
			move_left(vars);
			vars->moves++;
		}
	}
	if (keycode == 's')
	{
		if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y + 1))
		{
			move_down(vars);
			vars->moves++;
		}
	}
	if (keycode == 'w')
	{
		if (player_can_move(vars, vars->play_pos.x, vars->play_pos.y - 1))
		{
			move_up(vars);
			vars->moves++;
		}
	}
	put_free_space(vars);
	printf("moves : %d\n", vars->moves); // /!\ PRINTF !
	return (0);
}


void	put_player(t_mlx_datas *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_imgs.front.img, \
					vars->play_pos.x * vars->play_imgs.front.width, \
					vars->play_pos.y * vars->play_imgs.front.height);
}

void	put_animated_img(t_mlx_datas *vars, int img, int x, int y)
{
	if (img == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_0.img, x * \
		vars->collect_imgs.kunai_0.width, y * vars->collect_imgs.kunai_0.height);
	else if (img == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_1.img, x * \
		vars->collect_imgs.kunai_1.width, y * vars->collect_imgs.kunai_1.height);
	else if (img == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_2.img, x * \
		vars->collect_imgs.kunai_2.width, y * vars->collect_imgs.kunai_2.height);
	else if (img == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_3.img, x * \
		vars->collect_imgs.kunai_3.width, y * vars->collect_imgs.kunai_3.height);
	else if (img == 4)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_4.img, x * \
		vars->collect_imgs.kunai_4.width, y * vars->collect_imgs.kunai_4.height);
	else if (img == 5)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_5.img, x * \
		vars->collect_imgs.kunai_5.width, y * vars->collect_imgs.kunai_5.height);
	else if (img == 6)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_6.img, x * \
		vars->collect_imgs.kunai_6.width, y * vars->collect_imgs.kunai_6.height);
	else if (img == 7)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_7.img, x * \
		vars->collect_imgs.kunai_7.width, y * vars->collect_imgs.kunai_7.height);
	else if (img == 8)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_8.img, x * \
		vars->collect_imgs.kunai_8.width, y * vars->collect_imgs.kunai_8.height);
	else if (img == 9)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_9.img, x * \
		vars->collect_imgs.kunai_9.width, y * vars->collect_imgs.kunai_9.height);
	else if (img == 10)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect_imgs.kunai_10.img, x * \
		vars->collect_imgs.kunai_10.width, y * vars->collect_imgs.kunai_10.height);

}

void	put_collectible(t_mlx_datas *vars)
{
	static int i = 0;
	int x; 
	int y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'C')
				put_animated_img(vars, i, x, y);
			x++;
		}
		y++;
	}
	i++;
	if (i == 11)
		i = 1;
}

int	render_next_frame(t_mlx_datas *vars)
{
	static int i = 0;

	i++;
	if (i == 7500)
	{
		// put_free_space(vars);
		put_collectible(vars);
		i = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_datas	vars;
	t_map_datas	map_datas;
	char		**map;

	if (check_params(ac, av) == -1)
		return (-1);
	map = map_parser(&map_datas, av[1]);
	if (error_msg(map, "Invalid map.\n"))
		return (-1);
	vars.map_datas = map_datas;
	vars.map = map;
	if (init_mlx_datas_struct(&vars) == -1)
		return (-1);
	mlx_key_hook(vars.win, mov_key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars); // utiliser close_win dans mlx_key_hook ???
	init_tmp(&vars);
	init_map(&vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
