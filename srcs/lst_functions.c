/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:01:03 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/23 14:56:56 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**tab_cpy(char **tab)
{
	char **cpy;
	int i;

	i = 0;
	while (tab[i])
		i++;
	if (!(cpy = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		if(!(cpy[i] = strdup(tab[i])))
			return (NULL);
	}
	return (cpy);
}

t_tetri	*lst_new(char **tetri, int index)
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

void	lst_add_back(t_tetri **lst, t_tetri *new)
{
	t_tetri *current;

	if (!(lst))
	{
		ft_putendl("lst_add_back error : lst is NULL");
		return ;
	}
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

void	lst_iter(t_tetri *lst, void (*f)(t_tetri *ielem))
{
	t_tetri *cpy;

	if (!(lst))
	{
		ft_putendl("lst_iter error : lst is NULL");
		return ;
	}
	cpy = lst;
	while (cpy)
	{
		f(cpy);
		cpy = cpy->next;
	}
}

void	print_node(t_tetri *lst)
{
	int i;

	if (!(lst))
	{
		ft_putendl("print_node : WARNING, node is (null)");
		return ;
	}
	i = -1;
	ft_putstr("Tetrimino ");
	ft_putnbr(lst->index);
	ft_putendl(" : ");
	ft_putstrtab(lst->tetrimino);
}
