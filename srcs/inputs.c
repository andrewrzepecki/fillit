/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/23 20:09:27 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_elem(char **tetris, t_tetri **lst)
{
	char		**tmp;
	t_tetri		*new;
	static int	index;

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

int		check_tetris(char **tetris, t_tetri **lst)
{
	if (count_hash(**tetris) != 4)
		return (0);
	if (add_elem(tetris, lst))
		return (0);
	return (1);
}

int  	check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '.' && line[i] != '#')
            return (0);
        i++;
    }
    if (ft_strlen(line) != 4)
        return (0);
    return (1);
}
