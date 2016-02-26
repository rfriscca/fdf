/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:27:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/26 15:52:33 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		test_file(t_line *list)
{
	int		i;

	i = 0;
	while (list)
	{
		while (list->line[i])
		{
			if (ft_isdigit(list->line[i]))
				return (1);
			++i;
		}
		i = 0;
		list = list->next;
	}
	return (0);
}
