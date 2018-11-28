/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:01:03 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/28 13:00:07 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void		lst_del(t_tetri **lst)
{
	t_tetri *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		tab_free((*lst)->tetrimino);
		free((*lst)->tetrimino);
		free(*lst);
		(*lst) = tmp;
	}
	free(lst);
	lst = NULL;
}
