/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:09:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 05:32:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_parser_2(t_map_datas *map_datas, char *file)
{
	char	**map;

	map = malloc(sizeof(char *) * (map_datas->height + 1));
	if (error_msg(map, "Memory allocation has failed.\n"))
		return (NULL);
	if (fill_map(file, map) == -1)
	{
		ft_putstr("Error: Filling the map buffer has failed.\n");
		free(map);
		return (NULL);
	}
	if (is_valid_map(map, map_datas) == -1)
	{
		ft_putstr("Error: Invalid map. (parsing error)\n");
		free(map);
		return (NULL);
	}
	return (map);
}

char	**map_parser(t_map_datas *map_datas, char *file)
{
	init_map_datas_struct(map_datas);
	map_datas->height = get_line_number(file);
	if (map_datas->height == -1)
	{
		ft_putstr("Error: Getting the size of the map has failed.\n");
		return (NULL);
	}
	else if (map_datas->height < 3)
	{
		ft_putstr("Error: Invalid map. (map_datas->height < 3)\n");
		return (NULL);
	}
	return (map_parser_2(map_datas, file));
}
