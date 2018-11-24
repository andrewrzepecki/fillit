/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/24 18:00:54 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int          count_touch(char **tetris, int x, int y)
{
    int c;

    c = 0;
    if (tetris[x + 1][y] == '#')
        c++;
    if (tetris[x][y + 1] == '#')
        c++;
    if (tetris[x - 1][y] == '#')
        c++;
    if (tetris[x][y - 1] == '#')
        c++;
    return (c);
}

static int          check_tetris(char **tetris)
{
    int x;
    int y;
    int count;

    x = 1;
    count = 0;
    while (x < 5)
    {
        y = 1;
        while (y < 5)
        {
            if (tetris[x][y] == '#')
                count += count_touch(tetris, x, y);
            y++;
        }
        x++;
    }
    if (count > 5)
        return (1);
    else
        return (0);
}

static char         **reduce_tetris(char **tetris)
{
    char **red;

    red = NULL;
    if (check_tetris(tetris))
    {
        //reduce tetris into **red;
        ft_putstr("Valid Tetriminos\n");
        return (tetris);
    }
    return (NULL);

}

int		            set_tetris(char **tetris, t_tetri **lst, int index)
{
    char		**tmp;
    t_tetri		*new;
    int         count;
    int         i;

    i = 0;
    lst = NULL;
    count = 0;
    new = NULL;
    while (++i < 5)
        count += char_count(tetris[i], '#');
    if (count != 4)
        return (0);
    if (!(tmp = reduce_tetris(tetris)))
        return (0);
    index++;
   // if (!(new = lst_new(tmp, index)))
     //   return (0);
   // lst_add_back(lst, new);
    return (1);
}

