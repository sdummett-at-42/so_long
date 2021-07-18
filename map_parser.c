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
	while (ret != 0)
	{
		if (ret == -1)
			return (-1);
		ret = get_next_line(fd, &tmp);
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
			return (-1);
		ret = get_next_line(fd, &map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (0);
}

int	check_walls(char **map, int size)
{
	int	i;
	int	width;

	i = 0;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] != '1')
			return (-1);
		i++;
	}
	width = i;
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

int is_madara(char c)
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

int	is_free_space(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	map_has_player_exit_and_collectible(t_map_datas *map_datas)
{
	if (map_datas->player != 1)
		return (-1);
	if (map_datas->collectible == 0)
		return (-1);
	if (map_datas->exit == 0)
		return (-1);
	return (0);
}

int	check_map(char **map, t_map_datas *map_datas)
{
	int	i;
	int	j;

	i = 1;
	while (i < map_datas->height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((is_free_space(map[i][j]) || is_wall(map[i][j])) || \
			is_madara(map[i][j]))
			{
				j++;
				continue ;
			}
			else if (is_collectible(map[i][j]))
				map_datas->collectible += 1;
			else if (is_exit(map[i][j]))
				map_datas->exit += 1;
			else if (is_player(map[i][j]))
				map_datas->player += 1;
			else
				return (-1);
			j++;
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

char	**map_parser(t_map_datas *map_datas, char *file)
{
	char	**map;

	init_map_datas_struct(map_datas);
	map_datas->height = get_line_number(file);
	if (map_datas->height == -1)
	{
		ft_putstr("Error: Getting the map_datas->height of \
				the map has failed.\n");
		return (NULL);
	}
	else if (map_datas->height < 3)
	{
		ft_putstr("Error: Invalid map. (map_datas->height < 3)\n");
		return (NULL);
	}
	map = malloc(sizeof(char *) * map_datas->height + 1);
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