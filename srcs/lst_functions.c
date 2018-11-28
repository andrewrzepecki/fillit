/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:01:03 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/28 11:46:00 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tab_cpy(char **tab)
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

t_tetri		*lst_new(char **tetri, int index)
{
	t_tetri	*new;

	if (!(new = (t_tetri*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->tetrimino = tab_cpy(tetri)))
		return (NULL);
	new->index = index;
	new->next = NULL;
	return (new);
}

void		lst_add_back(t_tetri **lst, t_tetri *new)
{
	t_tetri *current;

	if (!(lst))
		return ;
	if (!(*lst))
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	current->next->next = NULL;
}

void		lst_iter(t_tetri *lst, void (*f)(t_tetri *ielem))
{
	t_tetri *cpy;

	if (!(lst))
		return ;
	cpy = lst;
	while (cpy)
	{
		f(cpy);
		cpy = cpy->next;
	}
}

size_t		ft_lstlen(t_tetri *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
