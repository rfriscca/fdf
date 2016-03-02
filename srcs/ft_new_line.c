/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:13:47 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/02 13:32:19 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*ft_new_line(char *line, int size)
{
	t_line	*list;
	int		i;

	i = 0;
	if ((list = (t_line*)malloc(sizeof(*list))) == NULL)
		return ((t_line*)0);
	if ((list->line = ft_strnew(size)) == NULL)
		return ((t_line*)0);
	list->next = NULL;
	while (i < size)
	{
		list->line[i] = line[i];
		++i;
	}
	list->size = size;
	return (list);
}
