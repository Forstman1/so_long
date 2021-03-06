/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:25:09 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/14 15:25:14 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	firstline(t_vars *var)
{
	int	y;

	y = 0;
	if (var->s[0][y] == '1')
	{
		while (var->s[0][y] == '1')
			y++;
		if (var->s[0][y] == '\0')
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

int	lastline(t_vars *var, int x)
{
	int	y;

	y = 0;
	if (var->s[x - 1][y] == '1')
	{
		while (var->s[x - 1][y] == '1')
			y++;
		if (var->s[x - 1][y] == '\0')
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

int	firstrow(t_vars *var, int x)
{
	int	x1;

	x1 = 1;
	while (var->s[x1] && var->s[x1][0] == '1')
		x1++;
	if (x1 != x)
		return (1);
	else
		return (0);
}

int	lastrow(t_vars *var, int x)
{
	int	y;
	int	x1;

	y = 0;
	x1 = 1;
	while (var->s[0][y])
		y++;
	while (var->s[x1] && var->s[x1][y - 1] == '1')
		x1++;
	if (x1 != x)
		return (1);
	else
		return (0);
}

int	checkthewallsbonus(t_vars *var)
{
	int	x;

	x = 0;
	while (var->s[x])
		x++;
	if (x < 3)
		errors();
	if (firstline(var))
		errors();
	if (lastline(var, x))
		errors();
	if (firstrow(var, x))
		errors();
	if (lastrow(var, x))
		errors();
	return (0);
}
