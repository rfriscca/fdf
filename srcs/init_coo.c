/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:28:47 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/01 12:41:02 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_seg	init_coo(int xi, int xf, int yi, int yf)
{
	t_seg	coo;

	coo.x[I] = xi;
	coo.x[F] = xf;
	coo.y[I] = yi;
	coo.y[F] = yf;
	coo.dx = xf - xi;
	coo.dy = yf - yi;
	coo.x[INC] = (coo.dx > 0) ? 1 : -1;
	coo.y[INC] = (coo.dy > 0) ? 1 : -1;
	coo.dx = ft_abs(coo.dx);
	coo.dy = ft_abs(coo.dy);
	return (coo);
}
