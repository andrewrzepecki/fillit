/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:30:15 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/27 14:44:28 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_beg(char **tetris)
{
	int i;

	i = 1;
	while (i < 5)
	{
		if (char_count(tetris[i], '#'))
			return (i);
		i++;
	}
	return (0);
}

int		get_start(char **tetris)
{
	int start;
	int tmp;
	int x;
	int y;

	x = 1;
	start = 6;
	while (x < 5)
	{
		y = 0;
		tmp = 42;
		while (tetris[x][y])
		{
			if (tetris[x][y] == '#' && tmp == 42)
				tmp = y;
			y++;
		}
		if (tmp < start)
			start = tmp;
		x++;
	}
	return (start);
}

int		get_end(char **tetris)
{
	int x;
	int y;
	int tmp;
	int end;

	x = 1;
	end = 0;
	while (x < 5)
	{
		y = ft_strlen(tetris[x]) - 1;
		while (tetris[x][y] != '#' && y >= 0)
			y--;
		tmp = y;
		if (tmp > end)
			end = tmp;
		x++;
	}
	return (end);
}

int		count_touch(char **tetris, int x, int y)
{
	int		c;

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

int		check_tetris(char **tetris)
{
	int		x;
	int		y;
	int		count;

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
