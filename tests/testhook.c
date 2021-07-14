/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:06:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/12 13:10:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// typedef struct	s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }		t_vars;

// int key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook\n");
// 	return (0);
// }

// int main()
// {
// 	t_vars vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }



int key_hook(int keycode, t_vars *vars)
{
	printf("keycode is : %d\n", keycode);
	return (0);
}

int mouse_hook(int mousecode, t_vars *vars)
{

	printf("mousecode is : %d\n", mousecode);
	
	printf("mouse_pos : x -> %d, y -> %d", vars->x, vars->y);
	return (0);
}

int main()
{
	t_vars vars;
	int x;
	int y;

	x = 0;
	y = 0;
	vars.x = 0;
	vars.y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "pepe");
	// mlx_key_hook(vars.win, key_hook, &vars);
	

	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	while (1)
	{
		mlx_mouse_get_pos(vars.mlx, vars.win, &vars.x, &vars.y);
		//mlx_mouse_move(vars.mlx, vars.win, vars.x, vars.y);
		printf("x : %d, y : %d\n", vars.x, vars.y);
	}
	//printf("x : %d | y : %d\n", vars.x, vars.y);
	// mlx_mouse_get_pos(vars.mlx, vars.win, &vars.x, &vars.y);
	//mlx_mouse_move(vars.mlx, vars.win, x, y);
	mlx_loop(vars.mlx);
}