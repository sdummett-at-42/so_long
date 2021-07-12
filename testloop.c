#include "minilibx-linux/mlx.h"
#include "fdf.h"

// Render a moving rainbow that shifts through all colors
// (screen turns red, becomes green and then becomes blue,
// then starts all over again).

typedef struct s_datas
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;

	int x;
	int y;
} t_datas;

int red_cross(int keycode, t_datas *vars)
{
	printf("red_cross\n");
	mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

int close_win(int keycode, t_datas *vars)
{
	if (keycode == 65307)
	{
		printf("close_win\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return 0;
}

void pixel_put(t_datas *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

// int render_next_frame(t_datas *vars)
// {
//     int x;
//     int y;

//     x = 0;
//     vars->img = mlx_new_image(vars->mlx, 500, 500);
//     vars->addr = mlx_get_data_addr(vars->img, \
	//     &vars->bpp, &vars->line_length, &vars->endian);
//     while (x < 300)
//     {
//         y = 0;
//         while (y < 300)
//         {
//             pixel_put(vars, x, y, 0xff0000);
//             y++;
//         }
//         x++;
//     }
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);    x = 0;
//     vars->img = mlx_new_image(vars->mlx, 500, 500);
//     vars->addr = mlx_get_data_addr(vars->img, \
	//     &vars->bpp, &vars->line_length, &vars->endian);
//     while (x < 300)
//     {
//         y = 0;
//         while (y < 300)
//         {
//             pixel_put(vars, x, y, 0x0080000);
//             y++;
//         }
//         x++;
//     }
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);    x = 0;
//     vars->img = mlx_new_image(vars->mlx, 500, 500);
//     vars->addr = mlx_get_data_addr(vars->img, \
	//     &vars->bpp, &vars->line_length, &vars->endian);
//     while (x < 300)
//     {
//         y = 0;
//         while (y < 300)
//         {
//             pixel_put(vars, x, y, 0x000000ff);
//             y++;
//         }
//         x++;
//     }
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
//     return (0);
// }

int render_next_frame(t_datas *vars)
{
	int x;
	int y;

	x = 0;
	vars->img = mlx_new_image(vars->mlx, 500, 500);
	vars->addr = mlx_get_data_addr(vars->img,
								   &vars->bpp, &vars->line_length, &vars->endian);
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			pixel_put(vars, x, y, 0x00ff00ff);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	x = 0;
	return (0);
}

int key_hook(int keycode, t_datas *vars)
{
	printf("keycode is %c\n", keycode);
	if (keycode == 'd')
	{
		vars->x += 10;
		if (vars->x < 0)
			vars->x = 0;
		else if (vars->x > 445)
			vars->x = 445;
	}
	if (keycode == 'a')
	{
		vars->x -= 10;
		if (vars->x < 0)
			vars->x = 0;
		else if (vars->x > 445)
			vars->y = 445;
	}
	if (keycode == 's')
	{
		vars->y += 10;
		if (vars->y < 0)
			vars->y = 0;
		else if (vars->y > 445)
			vars->y = 445;
	}
	if (keycode == 'w')
	{
		vars->y -= 10;
		if (vars->y < 0)
			vars->y = 0;
		else if (vars->y > 445)
			vars->y = 445;
	}
	return (0);
}

int main()
{
	t_datas vars;
	vars.x = 0;
	vars.y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "pepe");
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	mlx_hook(vars.win, 17, 1L << 1, red_cross, &vars);

	// create_image(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}