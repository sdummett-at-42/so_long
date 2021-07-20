/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 05:34:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 05:47:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** 	Check if the arg is valid.
*/

int	check_params(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("Please give a map with a .ber extension.\n");
		return (-1);
	}
	else if (ac > 2)
	{
		ft_putstr("Please give only one argument.\n");
		return (-1);
	}
	else
	{
		if (check_extension(av[1]) == -1)
		{
			ft_putstr("Please give a file with the right extension (.ber).\n");
			return (-1);
		}
	}
	return (0);
}

/*
** Check if the ptr is NULL and print an error message if it is.
*/

int	error_msg(void *ptr, char *msg)
{
	if (ptr == NULL)
	{
		ft_putstr(msg);
		return (1);
	}
	return (0);
}

int	close_win_cross(t_mlx_datas *vars)
{
	mlx_loop_end (vars->mlx);
	return (0);
}

int	close_win(int keysym, t_mlx_datas *vars)
{
	if (keysym == 65307)
		mlx_loop_end (vars->mlx);
	return (0);
}
