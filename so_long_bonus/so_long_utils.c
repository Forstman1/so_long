/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:40 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/14 15:24:43 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	declaringimages(t_vars *var)
{
	int	hei;
	int	wid;

	hei = 0;
	wid = 0;
	var->w = mlx_xpm_file_to_image(var->mlx, "./img/grass.xpm", &wid, &hei);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &wid, &hei);
	var->col = mlx_xpm_file_to_image(var->mlx, "./img/key3.xpm", &wid, &hei);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil1.xpm", &wid, &hei);
	var->d = mlx_xpm_file_to_image(var->mlx, "./img/door1.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm", &wid, &hei);
}

int	checkcollect(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (var->s[x])
	{
		y = 0;
		while (var->s[x][y])
		{
			if (var->s[x][y] == 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	deal_key(int key, t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 2)
		forward(var);
	if (key == 0)
		backward(var);
	if (key == 13)
		upward(var);
	if (key == 1)
		downward(var);
	if (key == 53)
		exit(0);
	mlx_clear_window(var->mlx, var->win);
	declaringimages(var);
	draw(var);
	return (0);
}
