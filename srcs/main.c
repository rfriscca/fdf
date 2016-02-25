/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/25 16:03:49 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	reset_window(t_stock stock)
{
	mlx_clear_window(stock.mlx, stock.win);
}

int		ft_exit(int n, void *param)
{
	if (n == 53)
		exit(n);
	if (n == 15)
		reset_window(*(t_stock*)param);
	return (0);
}

void	draw(t_stock stock, t_line *list)
{
	int		j;

	j = 0;
	while (list)
	{
		draw_line_h(stock, list, j);
		if (list->next)
			draw_line_v(stock, list, j);
		++j;
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_stock	stock;
	t_line	*list;
	int		fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	if (argc > 1)
		list = stock_file(fd);
	stock.mlx = mlx_init();
	stock.win = mlx_new_window(stock.mlx, 1920, 1080, "FDF");
	mlx_key_hook(stock.win, ft_exit, &stock);
	if (argc > 1)
		draw(stock, list);
	mlx_loop(stock.mlx);
	return (0);
}
