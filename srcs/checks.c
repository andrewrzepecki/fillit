/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:58:41 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/27 12:02:53 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_touch(char **tetris, int x, int y)
{
	int	c;

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

static int		check_tetris(char **tetris)
{
	int	x;
	int	y;
	int	count;

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

static char		**reduce_tetris(char **tetris, int height)
{
	int		i;
	int		start;
	int		end;
	int		beg;
	char	**red;

	red = NULL;
	if (check_tetris(tetris))
	{
		if (!(red = (char**)malloc(sizeof(char*) * (height + 1))))
			return (NULL);
		start = get_start(tetris);
		end = get_end(tetris);
		beg = get_beg(tetris);
		i = -1;
		while (++i < height)
		{
			if (!(red[i] = ft_strndup(tetris[beg] + start, (end - start + 1))))
				return (NULL);
			beg++;
		}
		red[i] = NULL;
		return (red);
	}
	return (NULL);
}

int				set_tetris(char **tetris, t_tetri **lst, int index)
{
	char		**tmp;
	int			height;
	int			count;
	int			i;
	int			c;

	i = 0;
	count = 0;
	height = 0;
	c  = 0;
	while (++i < 5)
	{
		if ((c = char_count(tetris[i], '#')))
			height++;
		count += c;
	}
	if (count != 4)
		return (0);
	if (!(tmp = reduce_tetris(tetris, height)))
		return (0);
    ft_tabprint(tmp);
    ft_putchar('\n');
	index++;
    lst = NULL;
	// if (!(new = lst_new(tmp, index)))
	//   return (0);
	// lst_add_back(lst, new);
	return (1);
}
