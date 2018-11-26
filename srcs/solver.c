/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:37:12 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/26 19:03:12 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include "libft2.h"
#include <stdio.h>


int valid_pos(char **tetris, char **grid, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (tetris[++i])
	{
		j = -1;
		while (tetris[i][++j])
			if (tetris[i][j] == '#' && grid[x + i][y + j] != '.')
				return (0);
	}
	return (1);
}

void	set_tetris(char **tetris, char **grid, int x, int y, char c)
{
	int i;
	int j;

	i = -1;
	while (tetris[++i])
	{
		j = -1;
		while (tetris[i][++j])
			if (tetris[i][j] == '#')
				grid[x + i][y + j] = c;
	}
}

/*
int recurssion(t_tetri **lst)
{

}
*/

char	**grid_init(t_tetri **lst, int *min_size)
{
	char	**grid;
	t_tetri	*current;
	int v_size;
	int h_size;
	
	current = *lst;
	*min_size = 0;
	v_size = 0;
	h_size = 0;
	while (current)
	{
		ft_putstrtab(current->tetrimino);
		v_size += ft_strlen(current->tetrimino[0]);
		while (*(current->tetrimino)++)
			h_size++;
		current = current->next;
	}
	*min_size = h_size > v_size ? h_size : v_size;
	if (!(grid = (char**)ft_memalloc(sizeof(char*) * (*min_size + 1))))
		return (NULL);
	h_size = -1;
	while (++h_size < *min_size)
	{
		if (!(grid[h_size] = (char*)ft_memalloc(sizeof(char) * (*min_size + 1))))
			return (NULL);
		ft_memset(grid[h_size], '.', *min_size);
	}
	return (grid);
}

int	fillit_solver(t_tetri **lst)
{
	int		*min_size;
	char	**grid;

	if (!(min_size = (int*)malloc(sizeof(int))))
			return (-1);
	if (!(grid = grid_init(lst, min_size)))
		return (-1);
	printf("min_size : %d\n", *min_size);
	ft_putstrtab(grid);
	return (0);;
}
