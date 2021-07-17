/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:54:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/17 20:08:24 by sdummett         ###   ########.fr       */
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
	int		width;
	int		height;
	int		x;
	int		y;
}	t_img_datas;

typedef struct s_player_imgs
{
	t_img_datas front;
	t_img_datas back;
	t_img_datas left;
	t_img_datas right;
}	t_player_imgs;

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

typedef struct s_player_pos
{
	int	x;
	int	y;
	int	last_x;
	int	last_y;

}	t_player_pos;

typedef struct s_mlx_datas
{
	void			*mlx;
	void			*win;
	char			**map;
	int				win_size_x;
	int				win_size_y;
	int				moves;
	int				tmp_free_space;
	t_img_datas		free_space;
	t_img_datas		wall;
	t_img_datas		collectible;
	t_img_datas		player; // ?? DELETE ??
	t_img_datas		exit;
	t_map_datas		map_datas;
	t_player_pos	play_pos;
	t_player_imgs	play_imgs;
	t_collect_imgs	collect_imgs;
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

/*
** DEBUGGING FUNCS
*/
void	print_map_datas(t_map_datas *map_datas);
void	print_buffer(char **map);

#endif
