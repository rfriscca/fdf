/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:33:11 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/21 17:22:49 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_tile(int x, int y, void *mlx, void *win)
{
	int		i;
	int		j;
	int		isox;
	int		isoy;

	i = 0;
	j = 0;
	isox = (x - y) * TILE_WIDTH + INIT_POS_X;
	isoy = (x + y) * TILE_HEIGHT / 2 + INIT_POS_Y;
	while (i < TILE_WIDTH)
	{
		mlx_pixel_put(mlx, win, isox + i, isoy + i, 0xffffff);
		mlx_pixel_put(mlx, win, isox + i + TILE_HEIGHT / 2, isoy + i - TILE_WIDTH, 0xffffff);
		++i;
	}
}
