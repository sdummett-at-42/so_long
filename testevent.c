/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testevent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:19:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/12 13:23:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"



//Whenever a key is pressed the window will close
// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 500, 500, "pepe");
// 	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
// 	mlx_loop(vars.mlx);
// }

//Whenever `Esc` is pressed the window will close
int	close_win(int keycode, t_vars *vars)
{
	printf("keycode is : %d\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

// int main()
// {
// 	t_vars vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 500, 500, "pepe");

// 	//mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

int red_cross(int keycode, t_vars *vars)
{
	printf("RED CROSS\n");
	mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

int hook_func(int keycode, t_vars *vars)
{
	printf("The window is closed.\n");
	return (0);
}

int key_is_pressed(void)
{
	printf("F key is being preeeeeeessed.\n");
	return 0;
}

int hello(void)
{
	printf("Hello!\n");
	return 0;
}
int bye(void)
{
	printf("Bye!\n");
	return 0;
}
int main()
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "pepe");
	mlx_hook(vars.win, 2, 1L<<0,close_win, &vars);
	mlx_hook(vars.win, 17, 1L<<1, red_cross, &vars);
	mlx_hook(vars.win, 7, 1L<<4, hello, &vars);
	mlx_hook(vars.win, 8, 1L<<5, bye, &vars);
	mlx_loop(vars.mlx);
}