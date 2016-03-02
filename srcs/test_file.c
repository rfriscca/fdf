/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:27:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/02 15:30:02 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		test_file(t_line *list)
{
	if (ft_isdigit(list->line[0]))
		return (1);
	if (list->line[0] == '-' && ft_isdigit(list->line[1]))
		return (1);
	return (0);
}
