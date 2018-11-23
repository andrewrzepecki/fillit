/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/24 00:40:19 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



int		add_elem(char **tetris, t_tetri **lst, int index)
{
	char		**tmp;
	t_tetri		*new;

	if (tmp = reduce_tetris(tetris))
		return (0);
	if (!(new = lst_new(tmp, index)))
		return (0);
	lst_add_back(lst, new);
	return (1);
}

int		count_hash(char **tetris)
{
	int x;
	int y;
	int hash;

	x = 0;
	hash = 0;
	while (x < 4)
	{
		y = -1;
		while (tetris[x][++y])
			if (tetris[x][y] == '#')
				hash++;
		x++;
	}
	return (hash);
}

int		check_tetris(char **tetris, t_tetri **lst, int index)
{
	if (count_hash(**tetris) != 4)
		return (0);
	if (add_elem(tetris, lst, index))
		return (0);
	return (1);
}

