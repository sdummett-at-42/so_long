/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:54:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:58:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	put_img(t_mlx_datas *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

/*
** Check the extension of the file given. (*.ber)
*/

static int	check_extension_2(int check, char c)
{
	if (check == 0 && c == 'r')
		return (1);
	else if (check == 1 && c == 'e')
		return (1);
	else if (check == 2 && c == 'b')
		return (1);
	else if (check == 3 && c == '.')
		return (1);
	return (-1);
}

int	check_extension(char *file)
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
		if (check_extension_2(check, file[i]) == 1)
			i--;
		else
			return (-1);
		check++;
	}
	if (check != 4)
		return (-1);
	return (0);
}
