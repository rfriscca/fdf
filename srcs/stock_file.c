/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:12:08 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/10 15:26:07 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*stock_file(int fd)
{
	int			ret;
	t_line		*list_start;
	t_line		*list;
	char		*line;
	int			i;

	i = 0;
	if ((ret = get_next_line(fd, &line)) == -1)
		return (NULL);
	if (ret <= 0 ||
			(list_start = ft_new_line(line, ft_strlen(line))) == (t_line*)0)
		return (NULL);
	list = list_start;
	if ((ret = get_next_line(fd, &line)) == -1)
		return (NULL);
	while (ret > 0)
	{
		if ((list->next = ft_new_line(line, ft_strlen(line))) == (t_line*)0)
			return (NULL);
		list = list->next;
		if ((ret = get_next_line(fd, &line)) == -1 || i == 10000)
			return (NULL);
		++i;
	}
	return (list_start);
}
