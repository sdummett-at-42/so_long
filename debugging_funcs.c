#include "so_long.h"

void print_map_datas(t_map_datas *map_datas)
{
	printf("width       : %d\n", map_datas->width);
	printf("height      : %d\n", map_datas->height);
	printf("collectible : %d\n", map_datas->collectible);
	printf("player      : %d\n", map_datas->player);
	printf("exit        : %d\n", map_datas->exit);
}

void print_buffer(char **map)
{
	while (*map != NULL)
	{
		printf("%s\n", *map);
		map++;
	}
}