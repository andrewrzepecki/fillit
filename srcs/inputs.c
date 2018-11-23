/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:23:13 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/24 00:43:57 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int      check_line(char *line)
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

static int      get_tetris(int fd, *line, char **tetris)
{
    int i;

    i = 0;
    while (i < 4)
    {
        get_next_line(fd, &line);
        if (!check_line(line))
            return (-1);
        if (!(tetris[i] = ft_strdup(line)))
            return (-1);
        ft_strdel(&(*line));
        i++;
    }
    return (1);
}    

int             read_file(int fd, char *line, char **tetris, t_tetri **lst)
{
    int index;
    int ret;
    int i;

    ret = 1;
    index = 0;
    while (ret)
    {
        if ((ret = get_tetris(fd, line, tetris) == -1)
            return (-1);
		ft_putstrtab(tetris);
        index++;
      /*  if (!check_tetris(tetris, lst, index))
            return (1); */
        ret = get_next_line(fd, &line);
        if (ret == -1 || (ret != 0  && *line))
		{
			ft_strdel(&line);
            return (-1);
		}
		if (ret != 0)
			ft_strdel(&line);
    }
    return (0);
}

