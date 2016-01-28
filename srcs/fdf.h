/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:47:21 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/28 15:00:45 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TILE_WIDTH 32
# define TILE_HEIGHT 32
# define INIT_POS_X 720
# define INIT_POS_Y 60
# define I 0
# define F 1
# define INC 2


# include <stdlib.h>
# include <mlx.h>
# include "libft.h"

void			create_tile(int x, int y, void *mlx, void *win);

typedef struct	s_seg
{
	int			x[3];
	int			y[3];
	int			dx;
	int			dy;
}				t_seg;

t_seg			init_coo(int xi, int xf, int yi, int yf);
void			seg(t_seg coo, void *mlx, void *win);
#endif
