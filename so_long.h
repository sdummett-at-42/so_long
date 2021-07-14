/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:54:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/14 13:03:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

// typedef struct s_img_datas
// {
// 	int width;
// 	int height;
// }				t_img_datas;

typedef struct s_mlx_datas
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
	int win_size_x;
	int win_size_y;
	int x;
	int y;
	int height;
	int width;
	//t_img_datas *img;
} t_mlx_datas;

int error_msg(void *ptr, char *msg);
int close_win(int keycode, t_mlx_datas *vars);
