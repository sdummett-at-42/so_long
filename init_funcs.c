#include "so_long.h"

static int init_img_datas_struct(t_mlx_datas *vars)
{
	vars->free_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/freespace.xpm", &vars->free_space.width, &vars->free_space.height);
	vars->free_space.x = 0;
	vars->free_space.y = 0;
	if (error_msg(vars->free_space.img, "Image reading has failed.\n"))
		return (-1);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/wall.xpm", &vars->wall.width, &vars->wall.height);
	vars->wall.x = 0;
	vars->wall.y = 0;
	if (error_msg(vars->wall.img, "Image reading has failed.\n"))
		return (-1);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/collectible.xpm", &vars->collectible.width, &vars->collectible.height);
	vars->collectible.x = 0;
	vars->collectible.y = 0;
	if (error_msg(vars->collectible.img, "Image reading has failed.\n"))
		return (-1);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/player.xpm", &vars->player.width, &vars->player.height);
	vars->player.x = 0;
	vars->player.y = 0;
	if (error_msg(vars->player.img, "Image reading has failed.\n"))
		return (-1);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, \
	"img/exit.xpm", &vars->exit.width, &vars->exit.height);
	vars->exit.x = 0;
	vars->exit.y = 0;
	if (error_msg(vars->exit.img, "Image reading has failed.\n"))
		return (-1);
	return (0);
}

int init_mlx_datas_struct(t_mlx_datas *vars)
{
	vars->mlx = mlx_init();
	if (error_msg(vars->mlx, "mlx_init has failed.\n"))
		return (0);
	vars->moves = 0;
	if (init_img_datas_struct(vars) == -1)
		return (-1);
	vars->win_size_x = vars->free_space.width * vars->map_datas.width;
	vars->win_size_y = vars->free_space.height * vars->map_datas.height;
	vars->win = mlx_new_window(vars->mlx, vars->win_size_x, vars->win_size_y, "so_long");
	if (error_msg(vars->win, "Opening a new window has failed.\n"))
		return (0);
	vars->free_space.tmp = 0;
	vars->wall.tmp = 0;
	vars->collectible.tmp = 0;
	vars->player.tmp = 0;
	vars->exit.tmp = 0;
	return (0);
}

void init_map_datas_struct(t_map_datas *map)
{
	map->width = 0;
	map->height = 0;
	map->collectible = 0;
	map->player = 0;
	map->exit = 0;
}

void init_put_exit(t_mlx_datas *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, x, y);
}

void init_put_collectible(t_mlx_datas *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x, y);
}

void init_put_player(t_mlx_datas *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, x, y);
}

void init_put_free_space(t_mlx_datas *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->free_space.img, x, y);
}

void init_put_wall(t_mlx_datas *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x, y);
}

void init_map(t_mlx_datas *vars)
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	i = 0;
	while (vars->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == '1')
				init_put_wall(vars, x, y);
			else if (vars->map[i][j] == '0')
				init_put_free_space(vars, x, y);
			else if (vars->map[i][j] == 'C')
				init_put_collectible(vars, x, y);
			else if (vars->map[i][j] == 'E')
				init_put_exit(vars, x, y);
			else if (vars->map[i][j] == 'P')
			{
				vars->play_pos.x = j;
				vars->play_pos.y = i; 
				vars->play_pos.last_x = j;
				vars->play_pos.last_y = i;
				init_put_player(vars, x, y);
			}
			x = x + vars->free_space.height;
			j++;
		}
		y = y + vars->free_space.width;
		i++;
	}
	//vars->tmp_free_space = 1; // <- USELESS ???
}