/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:54:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/14 21:12:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_map_datas
{
	int width;
	int height;
	int collectible;
	int player;
	int exit;
}				t_map_datas;

 typedef struct s_img_datas
 {
	void *img;
 	int width;
 	int height;
	int x;
	int y;
	int tmp; // to remove
 }				t_img_datas;

typedef struct s_mlx_datas
{
	void *mlx;
	void *win;
	int win_size_x;
	int win_size_y;
	int last_x_pos;
	int last_y_pos;
	int moves;
	int tmp_free_space;
	t_img_datas free_space;
	t_img_datas wall;
	t_img_datas collectible;
	t_img_datas player;
	t_img_datas exit;
} t_mlx_datas;

int error_msg(void *ptr, char *msg);
int close_win(int keycode, t_mlx_datas *vars);
int init_mlx_datas_struct(t_mlx_datas *vars);
void init_map(t_mlx_datas *vars);
void init_map_datas_struct(t_map_datas *map);
int check_params(int ac, char **av);
char **map_parser(t_map_datas *map_datas, char *file);
void ft_putstr(char *str);

/*
** DEBUGGING FUNCS
*/
void print_map_datas(t_map_datas *map_datas);
void print_buffer(char **map);