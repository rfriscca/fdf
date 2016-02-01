/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:47:21 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/01 14:22:16 by rfriscca         ###   ########.fr       */
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
# include <fcntl.h>

void			create_tile(int x, int y, void *mlx, void *win);

typedef struct	s_seg
{
	int			x[3];
	int			y[3];
	int			dx;
	int			dy;
}				t_seg;

typedef struct	s_stock
{
	void		*mlx;
	void		*win;
}				t_stock;

t_seg			init_coo(int xi, int xf, int yi, int yf);
void			seg(t_seg coo, void *mlx, void *win, int color);
t_list			*stock_file(int fd);

#endif
