/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:12:08 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/11 15:34:15 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*stock_file(int fd)
{
	int			ret;
	t_line		*list_start;
	t_line		*list;
	char		*line;

	ret = get_next_line(fd, &line);
	if (ret > 0)
	{
		list_start = ft_new_line(line, ft_strlen(line));
		list = list_start;
	}
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		list->next = ft_new_line(line, ft_strlen(line));
		list = list->next;
		ret = get_next_line(fd, &line);
	}
	return (list_start);
}
