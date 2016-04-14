/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:47:21 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/14 17:17:11 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TILE_WIDTH 1
# define TILE_HEIGHT 1
# define INIT_POS_X 860
# define INIT_POS_Y 50
# define I 0
# define F 1
# define INC 2
# define Z 3
# define V ft_atoi(v.value[i])

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

void				create_tile(int x, int y, void *mlx, void *win);

typedef	struct		s_value
{
	char			**value;
	char			**value2;
}					t_value;

typedef struct		s_seg
{
	int				x[3];
	int				y[3];
	int				dx;
	int				dy;
}					t_seg;

typedef struct		s_line
{
	char			*line;
	int				size;
	struct s_line	*next;
}					t_line;

typedef struct		s_stock
{
	void			*mlx;
	void			*win;
	t_line			*list;
	int				movex;
	int				movey;
	int				mult;
}					t_stock;

int					test_file(t_line *list);
int					dep(int x, int y, t_stock *param);
t_seg				init_coo(int xi, int xf, int yi, int yf);
void				seg(t_seg coo, void *mlx, void *win, int color);
void				draw_line_h(t_stock stock, t_line *list, int j, int mult);
void				draw_line_v(t_stock stock, t_line *list, int j, int mult);
void				draw(t_stock stock, int mult);
void				reset_window(t_stock stock);
void				ft_error_handler(int err_num);
t_line				*stock_file(int fd);
t_line				*ft_new_line(char *line, int size);

#endif
