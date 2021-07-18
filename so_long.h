/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:54:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 19:01:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_map_datas
{
	int	width;
	int	height;
	int	collectible;
	int	player;
	int	exit;
}	t_map_datas;

typedef struct s_img_datas
{
	void	*img;
	int		x;
	int		y;
}	t_img_datas;

typedef struct s_collect_imgs
{
	t_img_datas kunai_0;
	t_img_datas kunai_1;
	t_img_datas kunai_2;
	t_img_datas kunai_3;
	t_img_datas kunai_4;
	t_img_datas kunai_5;
	t_img_datas kunai_6;
	t_img_datas kunai_7;
	t_img_datas kunai_8;
	t_img_datas kunai_9;
	t_img_datas kunai_10;
}	t_collect_imgs;

typedef struct s_p_down
{
	t_img_datas	down;
	t_img_datas down_0;
	t_img_datas	down_1;
	t_img_datas	down_2;
	t_img_datas	down_3;
}	t_p_down;

typedef struct s_p_right
{
	t_img_datas right;
	t_img_datas right_0;
	t_img_datas right_1;
	t_img_datas right_2;
	t_img_datas right_3;
	t_img_datas right_4;
	t_img_datas right_5;
}	t_p_right;

typedef struct s_p_left
{
	t_img_datas left;
	t_img_datas left_0;
	t_img_datas left_1;
	t_img_datas left_2;
	t_img_datas left_3;
	t_img_datas left_4;
	t_img_datas left_5;
}	t_p_left;

typedef struct s_p_win
{
	t_img_datas win_0;
	t_img_datas win_1;
	t_img_datas win_2;
	t_img_datas win_3;
	t_img_datas win_4;
	t_img_datas win_5;
	t_img_datas win_6;
	t_img_datas win_7;
}	t_p_win;

typedef struct s_player_pos
{
	int	x;
	int	y;
	int	last_x;
	int	last_y;
	int	up;
	int	down;
	int left;
	int right;
	int is_moving;
	int	won;
	int lost;
}	t_player_pos;

typedef struct s_mlx_datas
{
	void			*mlx;
	void			*win;
	char			**map;
	int				width;
	int				height;
	int				win_size_x;
	int				win_size_y;
	int				moves;
	int				tmp_free_space;
	t_img_datas		free_space;
	t_img_datas		wall;
	t_img_datas		collectible;
	t_img_datas		exit;
	t_map_datas		map_datas;
	t_player_pos	play_pos;
	t_collect_imgs	collect_imgs;
	t_p_down		p_down;
	t_p_right		p_right;
	t_p_left		p_left;
	t_p_win			p_win;
}	t_mlx_datas;

int		error_msg(void *ptr, char *msg);
int		close_win(int keycode, t_mlx_datas *vars);
int		init_mlx_datas_struct(t_mlx_datas *vars);
void	init_map(t_mlx_datas *vars);
void	init_map_datas_struct(t_map_datas *map);
int		check_params(int ac, char **av);
char	**map_parser(t_map_datas *map_datas, char *file);
void	ft_putstr(char *str);
void	init_map(t_mlx_datas *vars);
void	put_img(t_mlx_datas *vars, void*img, int x, int y);
int		init_collectible_img_struct(t_mlx_datas *vars);
int		init_p_down_imgs(t_mlx_datas*vars);
int		init_p_right_imgs(t_mlx_datas *vars);
int		init_p_left_imgs(t_mlx_datas *vars);
void	move_up(t_mlx_datas *vars);
void	move_down(t_mlx_datas *vars);
void	move_left(t_mlx_datas *vars);
void	move_right(t_mlx_datas *vars);
void	win_animation(t_mlx_datas *vars);
void	put_collectible(t_mlx_datas *vars);
int		mov_key_hook(int keycode, t_mlx_datas *vars);
int init_p_win_imgs(t_mlx_datas *vars);


/*
** DEBUGGING FUNCS
*/
void	print_map_datas(t_map_datas *map_datas);
void	print_buffer(char **map);

#endif
