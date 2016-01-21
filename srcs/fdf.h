/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:47:21 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/21 17:16:38 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TILE_WIDTH 32
# define TILE_HEIGHT 32
# define INIT_POS_X 720
# define INIT_POS_Y 60

# include <stdlib.h>
# include <mlx.h>

void	create_tile(int x, int y, void *mlx, void *win);

#endif
