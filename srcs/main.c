/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:23:13 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/24 02:12:37 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    int     fd;
    int     ret;
    char    *line;
    char    **tetris;
    t_tetri **lst;

    fd = -42;
    if (!(tetris = (char**)ft_memalloc(sizeof(char*) * 5)) \
            || !(line = (char*)ft_memalloc(1)))
        return (1);
    if (ac == 2)
        if ((fd = open(av[1], O_RDONLY)) > 0)
		    ret = read_file(fd, line, tetris, lst);
    if (ft_print_errors(ac, fd, ret))
        return (1);
  //ft_print_solution(solve_fillit(&list, &content));
  return (0);
}
