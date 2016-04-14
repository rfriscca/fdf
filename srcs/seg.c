/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:43:57 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/01 12:43:13 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_seg_dy(t_seg coo, void *mlx, void *win, int color)
{
	int		cumul;
	int		i;
	int		x;
	int		y;

	x = coo.x[I];
	y = coo.y[I];
	i = 0;
	cumul = coo.dy / 2;
	while (i < coo.dy)
	{
		y = y + coo.y[INC];
		cumul = cumul + coo.dx;
		if (cumul >= coo.dy)
		{
			cumul = cumul - coo.dy;
			x = x + coo.x[INC];
		}
		mlx_pixel_put(mlx, win, x, y, color);
		++i;
	}
}

static void		put_seg_dx(t_seg coo, void *mlx, void *win, int color)
{
	int		cumul;
	int		i;
	int		x;
	int		y;

	x = coo.x[I];
	y = coo.y[I];
	i = 0;
	cumul = coo.dx / 2;
	while (i < coo.dx)
	{
		x = x + coo.x[INC];
		cumul = cumul + coo.dy;
		if (cumul >= coo.dx)
		{
			cumul = cumul - coo.dx;
			y = y + coo.y[INC];
		}
		mlx_pixel_put(mlx, win, x, y, color);
		++i;
	}
}

void			seg(t_seg coo, void *mlx, void *win, int color)
{
	mlx_pixel_put(mlx, win, coo.x[I], coo.y[I], color);
	if (coo.dx > coo.dy)
		put_seg_dx(coo, mlx, win, color);
	else
		put_seg_dy(coo, mlx, win, color);
}
