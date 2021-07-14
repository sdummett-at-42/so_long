/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:54:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/14 13:03:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error_msg(void *ptr, char *msg)
{
	if (ptr == NULL)
	{
		printf("%s", msg);
		return (1);
	}
	return (0);
}

int close_win(int keycode, t_mlx_datas *vars)
{
	if (keycode == 65307)
	{
		printf("Window closed.\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}