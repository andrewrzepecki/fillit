/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:16:46 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/28 12:42:39 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_sqrt_sup(int n)
{
	int c;

	c = 1;
	while (c * c < n)
		c++;
	return (c);
}

void			tab_free(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
}

char			**tab_cpy(char **tab)
{
	char	**cpy;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (!(cpy = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		if (!(cpy[i] = ft_strdup(tab[i])))
			return (NULL);
	}
	cpy[i] = NULL;
	return (cpy);
}
