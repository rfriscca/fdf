/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/29 16:50:45 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	reset_win(t_stock stock)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 1920)
	{
		while (j <= 1080)
		{
			mlx_pixel_put(stock.mlx, stock.win, i, j, 0x000000);
			++j;
		}
		j = 0;
		++i;
	}
}

int		ft_exit(int n, void *param)
{
	if (n == 53)
		exit(n);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		i;
	t_seg	coo;
	t_stock	stock;
	t_list	*list;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "FDF");
	stock.mlx = mlx;
	stock.win = win;
	mlx_key_hook(win, ft_exit, &stock);
	list = stock_file(fd);
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
		ft_putchar('\n');
	}
	mlx_loop(mlx);
	return (0);
}
