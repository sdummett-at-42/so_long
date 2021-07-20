/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_sprites_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:02:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 23:59:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_put_madara(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->madara.stand.img, x, y);
}
