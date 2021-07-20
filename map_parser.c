/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:56:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 04:07:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_number(char *file)
{
	int		size;
	int		fd;
	int		ret;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 1;
	ret = get_next_line(fd, &tmp);
	free(tmp);
	while (ret != 0)
	{
		if (ret == -1)
		{
			free(tmp);
			return (-1);
		}
		ret = get_next_line(fd, &tmp);
		free(tmp);
		size++;
	}
	close(fd);
	return (size);
}

int	fill_map(char *file, char **map)
{
	int	i;
	int	fd;
	int	ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &map[0]);
	i = 1;
	while (ret != 0)
	{
		if (ret == -1)
			return (free_map_buffer(map));
		ret = get_next_line(fd, &map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (0);
}

static int	get_width(char **map)
{
	int	i;

	i = 0;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] != '1')
			return (-1);
		i++;
	}
	return (i);
}

int	check_walls(char **map, int size)
{
	int	i;
	int	width;

	width = get_width(map);
	if (width < 3)
		return (-1);
	i = 0;
	while (map[size - 1][i] != '\0')
	{
		if (map[size - 1][i] != '1')
			return (-1);
		i++;
	}
	if (width != i)
		return (-1);
	while (*map != NULL)
	{
		if ((*map)[0] != '1')
			return (-1);
		if ((*map)[width - 1] != '1')
			return (-1);
		map++;
	}
	return (width);
}
