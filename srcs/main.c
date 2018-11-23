/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:23:13 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/23 16:44:42 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int read_file(int fd, char *line)
{
    int ret;

    ret = 1;
    while (ret)
    {
        i = 0;
        while (i < 4)
        {
            ret = get_next_line(fd, &line);
            if (ft_check_line(line))
                tetris[i] = ft_strdup(line);
            else
                return (1);
            free(line);
            i++;
        }
        if (!check_tetris(tetris, lst))
            return (1);
        if ((ret = get_next_line(fd, &line)) < 0)
            return (1);
        if (ft_strlen(line) != 1 && line[0] != '\n')
            return (1);
    }
    return (0);
}

int     main(int ac, char **av)
{
    int     fd;
    char    **content;
    t_tetri **lst;

    fd = -42;
    tetris = malloc(4);
    if (ac == 2)
        if ((fd = open(av[1], O_RDONLY)) > 0)
            if (read_file(fd, line))
            {
                ft_putstr_fd("error\n", 2);
                return (1);
            }
    if (ft_print_errors(ac, fd, ret))
        return (1);
    else
    {
        solve_fillit(&list, &content);
        ft_print_solution(content, ret);
    }
    return (0);
}
