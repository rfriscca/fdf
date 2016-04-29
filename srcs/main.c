/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/14 17:27:26 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_move(int n, t_stock *param)
{
	static int	y = 0;
	static int	x = 0;

	if (n == 123)
		--x;
	if (n == 124)
		++x;
	if (n == 125)
		++y;
	if (n == 126)
		--y;
	param->movex = x * 20;
	param->movey = y * 20;
	draw(*param, param->mult);
}

int		ft_exit(int n, t_stock *param)
{
	reset_window(*param);
	if (n == 53)
		exit(n);
	if (n == 69)
	{
		param->mult = param->mult + 5;
		draw(*param, param->mult);
		return (0);
	}
	if (n == 78 && param->mult != 5)
	{
		param->mult = param->mult - 5;
		draw(*param, param->mult);
		return (0);
	}
	ft_move(n, param);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stock	stock;
	int		fd;

	stock.movex = 0;
	stock.movey = 0;
	stock.mult = 25;
	if (argc != 2)
		ft_error_handler(1);
	if (argc > 1)
		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			ft_error_handler(2);
	if (argc > 1)
		if ((stock.list = stock_file(fd)) == NULL)
			ft_error_handler(3);
	if (test_file(stock.list) == 0)
		ft_error_handler(4);
	stock.mlx = mlx_init();
	stock.win = mlx_new_window(stock.mlx, 1920, 1080, "FDF");
	mlx_key_hook(stock.win, ft_exit, &stock);
	if (argc > 1 && test_file(stock.list))
		draw(stock, 25);
	mlx_loop(stock.mlx);
	return (0);
}
