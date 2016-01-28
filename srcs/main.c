/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/28 15:05:15 by rfriscca         ###   ########.fr       */
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
	t_seg	coo;

	coo = init_coo(10, 1900, 0, 720);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "FDF");
	mlx_key_hook(win, ft_exit, 0);
	seg(coo, mlx, win);
	mlx_loop(mlx);
	return (0);
}
