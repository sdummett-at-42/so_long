/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:06:36 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 03:17:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_madara(char c)
{
	if (c == 'M')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}

int	is_collectible(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}

int	is_exit(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}
