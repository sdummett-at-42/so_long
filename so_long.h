/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:54:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:13:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** # include <X11/keysym.h>
** # include <X11/X.h>
*/

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
	t_img_datas	kunai_0;
	t_img_datas	kunai_1;
	t_img_datas	kunai_2;
	t_img_datas	kunai_3;
	t_img_datas	kunai_4;
	t_img_datas	kunai_5;
	t_img_datas	kunai_6;
	t_img_datas	kunai_7;
	t_img_datas	kunai_8;
	t_img_datas	kunai_9;
	t_img_datas	kunai_10;
}	t_collect_imgs;

typedef struct s_p_down
{
	t_img_datas	down;
	t_img_datas	down_right_0;
	t_img_datas	down_right_1;
	t_img_datas	down_right_2;
	t_img_datas	down_right_3;
	t_img_datas	down_left_0;
	t_img_datas	down_left_1;
	t_img_datas	down_left_2;
	t_img_datas	down_left_3;
}	t_p_down;

typedef struct s_p_up
{
	t_img_datas	up;
	t_img_datas	up_right_0;
	t_img_datas	up_right_1;
	t_img_datas	up_right_2;
	t_img_datas	up_right_3;
	t_img_datas	up_left_0;
	t_img_datas	up_left_1;
	t_img_datas	up_left_2;
	t_img_datas	up_left_3;
}	t_p_up;

typedef struct s_p_right
{
	t_img_datas	right;
	t_img_datas	right_0;
	t_img_datas	right_1;
	t_img_datas	right_2;
	t_img_datas	right_3;
}	t_p_right;

typedef struct s_p_left
{
	t_img_datas	left;
	t_img_datas	left_0;
	t_img_datas	left_1;
	t_img_datas	left_2;
	t_img_datas	left_3;
}	t_p_left;

typedef struct s_p_win
{
	t_img_datas	win_0;
	t_img_datas	win_1;
	t_img_datas	win_2;
	t_img_datas	win_3;
	t_img_datas	win_4;
	t_img_datas	win_5;
	t_img_datas	win_6;
	t_img_datas	win_7;
}	t_p_win;

typedef struct s_madara
{
	t_img_datas	stand;
	t_img_datas	atk_0;
	t_img_datas	atk_1;
	t_img_datas	atk_2;
	t_img_datas	atk_3;
}	t_madara;

typedef struct s_tobi
{
	t_img_datas	stand;
	t_img_datas	exit_0;
	t_img_datas	exit_1;
	t_img_datas	exit_2;
}	t_tobi;

typedef struct s_p_lost
{
	t_img_datas	lost_0;
	t_img_datas	lost_1;
	t_img_datas	lost_2;
}	t_p_lost;

typedef struct s_ath
{
	t_img_datas	ath_0;
	t_img_datas	ath_1;
	t_img_datas	ath_2;
}	t_ath;
typedef struct s_anti_tearing
{
	t_img_datas	left16px;
	t_img_datas	left33px;
	t_img_datas	left50px;
	t_img_datas	right16px;
	t_img_datas	right33px;
	t_img_datas	right50px;
	t_img_datas	up16px;
	t_img_datas	up33px;
	t_img_datas	up50px;
	t_img_datas	down16px;
	t_img_datas	down33px;
	t_img_datas	down50px;
}	t_anti_tearing;

typedef struct s_player_infos
{
	int	x;
	int	y;
	int	last_x;
	int	last_y;
	int	up;
	int	down;
	int	left;
	int	right;
	int	look_right;
	int	is_moving;
	int	won;
	int	lost;
}	t_player_infos;

typedef struct s_move_count
{
	int	count;
	int	x;
	int	y;
}	t_move_count;

typedef struct s_mlx_datas
{
	void			*mlx;
	void			*win;
	char			**map;
	int				width;
	int				height;
	int				win_size_x;
	int				win_size_y;
	int				tmp_free_space;
	t_move_count	moves;
	t_player_infos	play_pos;
	t_img_datas		free_space;
	t_img_datas		wall;
	t_map_datas		map_datas;
	t_collect_imgs	collect_imgs;
	t_p_up			p_up;
	t_p_down		p_down;
	t_p_right		p_right;
	t_p_left		p_left;
	t_p_win			p_win;
	t_p_lost		p_lost;
	t_madara		madara;
	t_tobi			tobi;
	t_ath			ath;
	t_anti_tearing	tearing;
}	t_mlx_datas;

/*
** Map parsing
*/

int		is_madara(char c);
int		is_player(char c);
int		is_collectible(char c);
int		is_exit(char c);
int		is_wall(char c);
int		is_free_space(char c);
int		is_valid_map(char **map, t_map_datas *map_datas);
int		fill_map(char *file, char **map);
int		get_line_number(char *file);
int		check_walls(char **map, int size);

/*
**
*/

int		error_msg(void *ptr, char *msg);
int		close_win(int keysym, t_mlx_datas *vars);
int		close_win_cross(t_mlx_datas *vars);
int		init_mlx_datas_struct(t_mlx_datas *vars);
void	init_map(t_mlx_datas *vars);
void	init_map_datas_struct(t_map_datas *map);
int		check_params(int ac, char **av);
int		check_extension(char *file);
char	**map_parser(t_map_datas *map_datas, char *file);
void	ft_putstr(char *str);
void	init_map(t_mlx_datas *vars);
void	put_img(t_mlx_datas *vars, void*img, int x, int y);

/*
** Initialization functions
*/

void	init_put_madara(t_mlx_datas *vars, int x, int y);
void	init_put_wall(t_mlx_datas *vars, int x, int y);
void	init_put_free_space(t_mlx_datas *vars, int x, int y);
void	init_put_player(t_mlx_datas *vars, int x, int y);
void	init_put_collectible(t_mlx_datas *vars, int x, int y);
void	init_put_exit(t_mlx_datas *vars, int x, int y);
void	init_all_vars(t_mlx_datas *vars);
int		init_collectible_imgs(t_mlx_datas *vars);
int		init_ground_imgs(t_mlx_datas *vars);
int		init_wall_imgs(t_mlx_datas *vars);
int		init_p_up_right_imgs(t_mlx_datas*vars);
int		init_p_up_left_imgs(t_mlx_datas*vars);
int		init_p_down_left_imgs(t_mlx_datas *vars);
int		init_p_down_right_imgs(t_mlx_datas *vars);
int		init_p_right_imgs(t_mlx_datas *vars);
int		init_p_left_imgs(t_mlx_datas *vars);
int		init_p_win_imgs(t_mlx_datas *vars);
int		init_p_lost_imgs(t_mlx_datas *vars);
int		init_madara_imgs(t_mlx_datas *vars);
int		init_tobi_imgs(t_mlx_datas *vars);
int		init_ath(t_mlx_datas *vars);
void	init_map_ath(t_mlx_datas *vars);
int		init_anti_screentearing(t_mlx_datas *vars);

/*
** Animation related functions
*/

void	put_ath(t_mlx_datas *vars);
void	put_free_space(t_mlx_datas *vars);
int		player_can_move(t_mlx_datas *vars, int x, int y);
void	move_up_right(t_mlx_datas *vars);
void	move_up_left(t_mlx_datas *vars);
void	move_down_right(t_mlx_datas *vars);
void	move_down_left(t_mlx_datas *vars);
void	move_left(t_mlx_datas *vars);
void	move_right(t_mlx_datas *vars);
void	win_animation(t_mlx_datas *vars);
void	lost_animation(t_mlx_datas *vars);
void	madara_atk_animation(t_mlx_datas *vars);
void	tobi_tp_animation(t_mlx_datas *vars);
void	put_collectible(t_mlx_datas *vars);
int		mov_key_hook(int keycode, t_mlx_datas *vars);

/*
** Misc
*/

char	*ft_itoa(int n);
void	free_all_vars(t_mlx_datas *vars);
int		free_map_buffer(char **map);

#endif