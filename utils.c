/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:54:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 13:22:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Classic ft_putstr.
*/

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/*
** put_img is less verbose than mlx_put_image_to_window.
*/

void put_img(t_mlx_datas *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

/*
** Check the extension of the file given. (*.ber)
*/

static int	check_extension(char *file)
{
	int	i;
	int	check;

	i = 0;
	while (file[i] != '\0')
		i++;
	if (i == 0)
		return (-1);
	i--;
	check = 0;
	while (i != 0 && check != 4)
	{
		if (check == 0 && file[i] == 'r')
			i--;
		else if (check == 1 && file [i] == 'e')
			i--;
		else if (check == 2 && file[i] == 'b')
			i--;
		else if (check == 3 && file[i] == '.')
			i--;
		else
			return (-1);
		check++;
	}
	if (check != 4)
		return (-1);
	return (0);
}

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

int	close_win(int keycode, t_mlx_datas *vars)
{
	if (keycode == 65307)
	{
		ft_putstr("Window closed.\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}
