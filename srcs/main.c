/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:23:13 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/23 20:00:43 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int  read_file(int fd, char *line, char **tetris, t_tetri **lst)
{
    int ret;
    int i;

    ret = 1;
    while (ret)
    {
        i = -1;
        while (++i < 4)
        {
            ret = get_next_line(fd, &line);
            if (!check_line(line))
			{
             	printf("error check_line\n");
			 	return (1);
			}
            tetris[i] = ft_strdup(line);
            free(line);
        }
		ft_putstrtab(tetris);
      /*  if (!check_tetris(tetris, lst))
            return (1); */
        ret = get_next_line(fd, &line);
        if (ret == -1 || (ret != 0  && *line))
		{
			ft_strdel(&line);
            return (1);
		}
		if (ret != 0)
			ft_strdel(&line);
    }
    return (0);
}

int     main(int ac, char **av)
{
    int     fd;
    char    *line;
    char    **tetris;
    t_tetri **lst;

    fd = -42;
    if (!(tetris = (char**)ft_memalloc(sizeof(char*) * 5)) \
            || !(line = (char*)ft_memalloc(1)))
        return (1);
    if (ac == 2)
        if ((fd = open(av[1], O_RDONLY)) > 0)
		{
		 	if (read_file(fd, line, tetris, lst))
            {
                ft_putstr_fd("error\n", 2);
                return (1);
            }
		}
    /*if (ft_print_errors(ac, fd, ret))
        return (1);
    else
    {
        solve_fillit(&list, &content);
        ft_print_solution(content, ret);
    }*/
    return (0);
}
