/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:58:41 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/28 13:47:42 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	t_tetri		*new;
	char		**tmp;
	int			height;
	int			count;
	int			i;

	i = 0;
	count = 0;
	height = 0;
	while (++i < 5)
	{
		if (char_count(tetris[i], '#'))
			height++;
		count += char_count(tetris[i], '#');
	}
	if (count != 4)
		return (0);
	if (!(tmp = reduce_tetris(tetris, height)))
		return (0);
	if (!(new = lst_new(tmp, index)))
		return (0);
	tab_free(tmp);
	free(tmp);
	lst_add_back(lst, new);
	return (1);
}
