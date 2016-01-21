/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/21 15:53:04 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_exit(int n)
{
	if (n == 53)
		exit(n);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "FDF");
	mlx_key_hook(win, ft_exit, 0);
	mlx_loop(mlx);
	return (0);
}
