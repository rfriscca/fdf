/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:17:31 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/14 17:32:13 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_handler(int err_num)
{
	if (err_num == 1)
		ft_putstr("Please enter only one argument\n");
	else if (err_num == 2)
		ft_putstr("Read error\nMake sure your file is an existing file\n");
	else if (err_num == 3)
		ft_putstr("Read error\nMaybe you tried to read a directory\n");
	else if (err_num == 4)
		ft_putstr("Error not a valid file\n");
	exit(0);
}
