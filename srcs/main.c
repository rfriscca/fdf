/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:11:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/11 15:36:04 by rfriscca         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_seg	coo;
	int		x;
	int		y;
	char	**value;
	char	**value2;
	t_stock	stock;
	t_line	*list;
	int		fd;
	int		i;
	int		j;
	int		color;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	color = 0xffffff;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	if (argc > 1)
		list = stock_file(fd);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "FDF");
	if (argc > 1)
	{
		while (list)
		{
			value = ft_strsplit(list->line, ' ');
			y = INIT_POS_Y + j * TILE_HEIGHT;
			if (list->next)
				value2 = ft_strsplit(list->next->line, ' ');
			while (value[i + 1])
			{
				x = INIT_POS_X + i * TILE_WIDTH - j * TILE_WIDTH;
				y = (i > 0) ? y + TILE_HEIGHT / 2 : y;
				coo = init_coo(x, x + TILE_WIDTH, y - Z * ft_atoi(value[i]), y + TILE_HEIGHT / 2 - Z * ft_atoi(value[i + 1]));
				if (ft_atoi(value[i]) > 0 || ft_atoi(value[i + 1]) > 0)
					color = 0xff00ff;
				seg(coo, mlx, win, color);
				color = 0xffffff;
				if (list->next)
				{
					coo = init_coo(x, x - TILE_WIDTH, y - Z * ft_atoi(value[i]), y + TILE_HEIGHT - Z * ft_atoi(value2[i]));
					if(ft_atoi(value[i]) > 0 || ft_atoi(value2[i]) > 0)
						color = 0xff00ff;
					seg(coo, mlx, win, color);
					color = 0xffffff;
				}
				++i;
			}
			if (list->next)
			{
				x = INIT_POS_X + i * TILE_WIDTH - j * TILE_WIDTH;
				y = y + TILE_HEIGHT / 2;
				coo = init_coo(x, x - TILE_WIDTH, y, y + TILE_HEIGHT);
				seg(coo, mlx, win, color);
			}
			i = 0;
			++j;
			list = list->next;
		}
	}
	stock.mlx = mlx;
	stock.win = win;
	mlx_key_hook(win, ft_exit, &stock);
	mlx_loop(mlx);
	return (0);
}
