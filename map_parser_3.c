/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:07:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 04:10:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_has_player_exit_and_collectible(t_map_datas *map_datas)
{
	if (map_datas->player != 1)
		return (-1);
	if (map_datas->collectible == 0)
		return (-1);
	if (map_datas->exit == 0)
		return (-1);
	return (0);
}

static int	check_char(t_map_datas *map_datas, char c)
{
	if ((is_free_space(c) || is_wall(c)) || \
			is_madara(c))
		return (1);
	else if (is_collectible(c))
		map_datas->collectible += 1;
	else if (is_exit(c))
		map_datas->exit += 1;
	else if (is_player(c))
		map_datas->player += 1;
	else
		return (-1);
	return (1);
}

static int	check_map(char **map, t_map_datas *map_datas)
{
	int	i;
	int	j;

	i = 1;
	while (i < map_datas->height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_char(map_datas, map[i][j]) != -1)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (map_has_player_exit_and_collectible(map_datas));
}

int	is_valid_map(char **map, t_map_datas *map_datas)
{
	map_datas->width = check_walls(map, map_datas->height);
	if (map_datas->width == -1)
		return (-1);
	if (check_map(map, map_datas) == -1)
		return (-1);
	return (0);
}
