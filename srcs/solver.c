/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:37:12 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/27 19:28:16 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int valid_pos(char **tetris, char **grid, int *pos, int min_size)
{
	int i;
	int j;

	i = 0;
	while (tetris[i])
		i++;
	if (pos[0] + i > min_size || \
			pos[1] + ft_strlen(tetris[0]) > min_size)
		return (0);
	i = -1;
	while (tetris[++i])
	{
		j = -1;
		while (tetris[i][++j])
		{
			if (tetris[i][j] == '#' && grid[pos[0] + i][pos[1] + j] != '.')
				return (0);
		}
	}
	return (1);
}

void	write_tetris(char **tetris, char **grid, int *pos, char c)
{
	int i;
	int j;

	i = -1;
	while (tetris[++i])
	{
		j = -1;
		while (tetris[i][++j])
		{
			if (tetris[i][j] == '#')
				grid[pos[0] + i][pos[1] + j] = c;
		}
	}
}

int recurssion(char **grid, t_tetri *lst, int min_size)
{
	int x;
	int y;
	int pos[2];

	x = -1;
	if (!(lst))
		return (1);
	while (grid[++x])
	{
		y = -1;
		while (grid[x][++y])
		{
			pos[0] = x;
			pos[1] = y;
			if (valid_pos(lst->tetrimino, grid, pos, min_size))
			{

				write_tetris(lst->tetrimino, grid, pos, lst->index + 64);
				if (recurssion(grid, lst->next, min_size))
					return (1);
				else
					write_tetris(lst->tetrimino, grid, pos, '.');
			}
			//			}
	}
}
return (0);
}

char	**grid_init(int min_size)
{
	char	**grid;
	int		i;

	if (!(grid = (char**)ft_memalloc(sizeof(char*) * (min_size + 1))))
		return (NULL);
	i = -1;
	while (++i < min_size)
	{
		if (!(grid[i] = (char*)ft_memalloc(sizeof(char) * (min_size + 1))))
			return (NULL);
		ft_memset(grid[i], '.', min_size);
	}
	return (grid);
}

char	**fillit_solver(t_tetri **lst)
{
	int		min_size;
	char	**grid;
	int 	pos[2];

	min_size = ft_sqrt_sup(ft_lstlen(*lst) * 4);
	if (!(grid = grid_init(min_size)))
		return (NULL);
	printf("min_size : %d\n", min_size);
	while (!(recurssion(grid, *lst, min_size)))
	{
		min_size++;
		tab_free(grid);
		grid = grid_init(min_size);
		printf("min_size : %d\n", min_size);
	}
	return (grid);
}
