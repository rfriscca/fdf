/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/26 15:49:57 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	reset_window(t_stock stock)
{
	mlx_clear_window(stock.mlx, stock.win);
}

void	draw(t_stock stock, int mult)
{
	int		j;

	j = 0;
	while (stock.list)
	{
		draw_line_h(stock, stock.list, j, mult);
		if (stock.list->next)
			draw_line_v(stock, stock.list, j, mult);
		++j;
		stock.list = stock.list->next;
	}
}

int		ft_exit(int n, t_stock *param)
{
	if (n == 53)
		exit(n);
	if (n == 69)
	{
		param->mult = param->mult + 5;
		reset_window(*param);
		draw(*param, param->mult);
	}
	if (n == 78 && param->mult != 5)
	{
		param->mult = param->mult - 5;
		reset_window(*param);
		draw(*param, param->mult);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stock	stock;
	int		fd;

	stock.movex = 0;
	stock.movey = 0;
	stock.mult = 25;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	if (argc > 1)
		stock.list = stock_file(fd);
	stock.mlx = mlx_init();
	stock.win = mlx_new_window(stock.mlx, 1920, 1080, "FDF");
	mlx_key_hook(stock.win, ft_exit, &stock);
	if (argc > 1 && test_file(stock.list))
	{
		mlx_hook(stock.win, 6, (1L << 8), dep, &stock);
		draw(stock, 25);
	}
	mlx_loop(stock.mlx);
	return (0);
}
