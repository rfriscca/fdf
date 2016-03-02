/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:59:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/02 13:02:32 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		list_len(t_line *list)
{
	int		i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}

int		list_line(t_line *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (list->line[i + 1])
	{
		if (list->line[i] != ' ' && list->line[i + 1] == ' ')
			++j;
		++i;
	}
	return (j);
}

int		dep(int x, int y, t_stock *param)
{
	static int		x2 = 0 + INIT_POS_X;
	static int		y2 = 0 + INIT_POS_Y;
	static int		mult = 0;

	if (mult != param->mult)
	{
		x2 = list_line(param->list) * param->mult / 5 *
			TILE_WIDTH + INIT_POS_X;
		y2 = list_len(param->list) * (param->mult / 2 * TILE_HEIGHT
				+ param->mult / 4 * TILE_HEIGHT) + INIT_POS_Y;
		mult = param->mult;
	}
	reset_window(*param);
	param->movex = x - x2;
	param->movey = y - y2;
	draw(*param, param->mult);
	return (0);
}
