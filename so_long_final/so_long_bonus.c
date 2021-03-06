/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:19 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/14 15:24:21 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <time.h>

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	int		i;

	i = 0;
	save[0] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\0')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	return (ft_strdup(save));
}

int	close1(int key)
{
	key = 0;
	exit(0);
	return (0);
}

void	drawingfunc(t_vars	*var)
{
	declaringimages(var);
	mlx_loop_hook(var->mlx, animations, var);
	mlx_key_hook(var->win, deal_key, var);
	mlx_hook(var->win, 17, 0, close1, (void *)0);
}

void	spliting(t_vars	*var, int fd, int *y2, int *x2)
{
	char	*a;
	int		temp;

	temp = 0;
	a = get_next_line(fd);
	if (a == NULL || a[0] == '\n')
		errors();
	var->s = ft_split(a, '\n');
	if (var->s == NULL)
		errors();
	(*y2) = ft_strlen(var->s[0]);
	while (var->s[(*x2)])
	{
		temp = ft_strlen(var->s[(*x2)]);
		if (temp != (*y2))
			errors();
		(*x2)++;
	}
	free(a);
}

int	main(int argc, char *argv[])
{
	t_vars	var;
	int		fd;
	int		x2;
	int		y2;

	x2 = 0;
	y2 = 0;
	var.loop = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		spliting(&var, fd, &y2, &x2);
		if (checkvalid(argv[1], &var))
			return (0);
		close(fd);
		var.mlx = mlx_init();
		var.win = mlx_new_window(var.mlx, 50 * y2, 50 * x2, "Forstman Funds");
		if (checkthewallsbonus(&var))
			errors();
		drawingfunc(&var);
		mlx_loop(var.mlx);
	}
	errors();
	return (0);
}
