/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:12:08 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/29 16:49:58 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list		*stock_file(int fd)
{
	int			ret;
	t_list		*list_start;
	t_list		*list;
	char		*line;

	ret = get_next_line(fd, &line);
	if (ret > 0)
	{
		list_start = ft_lstnew((char*)line, ft_strlen(line));
		list = list_start;
	}
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		list->next = ft_lstnew((char*)line, ft_strlen(line));
		list = list->next;
		ret = get_next_line(fd, &line);
	}
	return (list_start);
}
