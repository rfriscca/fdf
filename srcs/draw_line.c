/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:45:52 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/25 15:59:22 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_v(t_stock stock, t_line *list, int j)
{
	t_value v;
	int		i;
	int		x;
	int		y;
	t_seg	coo;

	i = 0;
	y = INIT_POS_Y + j * TILE_HEIGHT;
	v.value = ft_strsplit(list->line, ' ');
	v.value2 = ft_strsplit(list->next->line, ' ');
	while (ft_strcmp("end_of_tab", v.value[i]) &&
			ft_strcmp("end_of_tab", v.value2[i]))
	{
		x = INIT_POS_X + i * TILE_WIDTH - j * TILE_WIDTH;
		y = (i > 0) ? y + TILE_HEIGHT / 2 : y;
		coo = init_coo(x, x - TILE_WIDTH, y - Z * ft_atoi(v.value[i]),
				y + TILE_HEIGHT - Z * ft_atoi(v.value2[i]));
		seg(coo, stock.mlx, stock.win, 0xffffff);
		++i;
	}
	free(v.value);
	free(v.value2);
}

void	draw_line_h(t_stock stock, t_line *list, int j)
{
	char	**value;
	int		i;
	int		x;
	int		y;
	t_seg	coo;

	i = 0;
	y = INIT_POS_Y + j * TILE_HEIGHT;
	value = ft_strsplit(list->line, ' ');
	while (ft_strcmp("end_of_tab", value[i + 1]))
	{
		x = INIT_POS_X + i * TILE_WIDTH - j * TILE_WIDTH;
		y = (i > 0) ? y + TILE_HEIGHT / 2 : y;
		coo = init_coo(x, x + TILE_WIDTH, y - Z * ft_atoi(value[i]),
				y + TILE_HEIGHT / 2 - Z * ft_atoi(value[i + 1]));
		seg(coo, stock.mlx, stock.win, 0xfffffff);
		++i;
	}
	free(value);
}
