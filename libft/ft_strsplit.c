/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:41:30 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/07 16:22:11 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_taballoc_line(char **tab, char const *s, char c, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j != 0)
		{
			if ((tab[k] = ft_strnew(j)) == NULL)
				return (NULL);
			++k;
		}
		j = 0;
	}
	tab[k] = "end_of_tab";
	return (tab);
}

static char	**ft_taballoc(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || i == 0))
			j++;
		i++;
	}
	if ((tab = (char**)malloc((j + 2) * sizeof(*tab))) == NULL)
		return (NULL);
	if ((tab = ft_taballoc_line(tab, s, c, 0)) == NULL)
		return (NULL);
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	if ((tab = ft_taballoc(s, c)) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			tab[k][j] = ((char*)s)[i];
			i++;
			j++;
		}
		if (j != 0)
			k++;
		j = 0;
	}
	return (tab);
}
