/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:45:52 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/01 12:41:49 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		switch_color(int n)
{
	if (n == 0)
		return (0xffffff);
	if (n > 0)
		return (0x5c420f);
	if (n < 0)
		return (0x2a37f0);
	return (0);
}

void	draw_line_v(t_stock stock, t_line *list, int j, int mult)
{
	t_value v;
	int		i;
	int		x;
	int		y;
	t_seg	coo;

	i = 0;
	y = INIT_POS_Y + stock.movey + j * TILE_HEIGHT * mult;
	v.value = ft_strsplit(list->line, ' ');
	v.value2 = ft_strsplit(list->next->line, ' ');
	while (ft_strcmp("end_of_tab", v.value[i]) &&
			ft_strcmp("end_of_tab", v.value2[i]))
	{
		x = INIT_POS_X + stock.movex + i * TILE_WIDTH *
			mult - j * TILE_WIDTH * mult;
		y = (i > 0) ? y + TILE_HEIGHT * mult / 2 : y;
		coo = init_coo(x, x - TILE_WIDTH * mult, y - mult / 5 * V,
				y + TILE_HEIGHT * mult - mult / 5 * ft_atoi(v.value2[i]));
		seg(coo, stock.mlx, stock.win, switch_color(ft_atoi(v.value[i])));
		if (ft_atoi(v.value2[i]) != 0)
			seg(coo, stock.mlx, stock.win, switch_color(ft_atoi(v.value2[i])));
		++i;
	}
	free(v.value);
	free(v.value2);
}

void	draw_line_h(t_stock stock, t_line *list, int j, int mult)
{
	char	**value;
	int		i;
	int		x;
	int		y;
	t_seg	coo;

	i = 0;
	y = INIT_POS_Y + stock.movey + j * TILE_HEIGHT * mult;
	value = ft_strsplit(list->line, ' ');
	while (ft_strcmp("end_of_tab", value[i + 1]))
	{
		x = INIT_POS_X + stock.movex + i * TILE_WIDTH * mult -
			j * TILE_WIDTH * mult;
		y = (i > 0) ? y + TILE_HEIGHT * mult / 2 : y;
		coo = init_coo(x, x + TILE_WIDTH * mult, y - mult / 5 *
				ft_atoi(value[i]),
				y + TILE_HEIGHT * mult / 2 - mult / 5 * ft_atoi(value[i + 1]));
		seg(coo, stock.mlx, stock.win, switch_color(ft_atoi(value[i + 1])));
		if (ft_atoi(value[i]) != 0)
			seg(coo, stock.mlx, stock.win, switch_color(ft_atoi(value[i])));
		++i;
	}
	free(value);
}
