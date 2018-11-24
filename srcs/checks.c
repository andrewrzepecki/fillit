/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/24 02:11:12 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int          check_tetris(char **tetris)
{
    int x;
    int y;
    int pos[4][4];

    x = 0;
    while (++x < 4)
    {
        y = -1;
        while (++y < 4)
        {
            if pos
            pos[x][y] = 0;
        }
    }
}

static t_tetri      *reduce_tetris(char **tetris)
{
    if (check_tetris(tetris))
    {
            
    }
    return (NULL);
    
}

int		            set_tetris(char **tetris, t_tetri **lst, int index)
{
	char		**tmp;
	t_tetri		*new;
    int         count;
    int         i;

    i = -1;
    count = 0;
    while (++i < 4)
        count += char_count(tetris[i]);
    if (count != 4)
        return (0);
	if (!(tmp = reduce_tetris(tetris)))
		return (0);
	if (!(new = lst_new(tmp, index)))
		return (0);
	lst_add_back(lst, new);
	return (1);
}

