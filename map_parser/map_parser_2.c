/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:09:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:59:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**map_parser_2(t_map_datas *map_datas, char *file)
{
	char	**map;

	map = malloc(sizeof(char *) * (map_datas->height + 1));
	if (error_msg(map, "Error\nMemory allocation has failed.\n"))
		return (NULL);
	if (fill_map(file, map) == -1)
	{
		ft_putstr("Error\nFilling the map buffer has failed.\n");
		free_map_buffer(map);
		return (NULL);
	}
	if (is_valid_map(map, map_datas) == -1)
	{
		free_map_buffer(map);
		return (NULL);
	}
	return (map);
}

char	**map_parser(t_map_datas *map_datas, char *file)
{
	init_map_datas_struct(map_datas);
	map_datas->height = get_line_number(file);
	if (map_datas->height == -1)
		return (NULL);
	else if (map_datas->height < 3)
		return (NULL);
	return (map_parser_2(map_datas, file));
}
