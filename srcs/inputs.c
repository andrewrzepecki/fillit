/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:23:13 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/24 14:29:20 by anrzepec         ###   ########.fr       */
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
    int     i;
    char    blank[6];

    blank = (char*)ft_memset(blank, '.', 6);
    i = 0;
    if (!(tetris[i++] = ft_strdup(blank)))
        return (-1);
    while (i < 5)
    {
        get_next_line(fd, &line);
        if (!check_line(line))
            return (-1);
        if (!(tetris[i] = (char*)ft_memalloc(7)))
            return (-1);
        tetris[i] = (char*)ft_memset(tetris[i], '.', 6);
        tetris[i] = (char*)ft_memcpy(tetris[i] + 1, line, 4);
        ft_strdel(&(*line));
        i++;
    }
    if (!(tetris[i] = ft_strdup(blank)))
        return (-1);
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
        if ((ret = get_tetris(fd, line, tetris) == -1))
            return (-1);
		ft_putstrtab(tetris);
        index++;
        if (!set_tetris(tetris, lst, index))
            return (-1);
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
