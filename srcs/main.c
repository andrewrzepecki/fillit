/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:57:22 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/22 13:56:17 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    int     fd;
    int     ret;
    char    *content;

    ret = -42;
    fd = -42;
    if (ac == 2)
        if ((fd = open(av[1], O_RDONLY)) > 0)
            if ((ret = read_file(fd, &content)) > 0)
                solve_fillit(ret, &content);
    if (ft_print_errors(ac, fd, ret))
        return (1);
    else
        ft_print_solution(content, ret);
    return (0);
}
