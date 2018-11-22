/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/22 13:56:12 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  input_check(char *res)
{
    //verification l'input
    // return -2 si non valide
    // return 4 ou 8 selon le nombre de grilles tetriminos
}

int         read_file(int fd, char **content)
{
    int     ret;
    char    buff[BUFF_SIZE + 1];
    char    *res;
    char    *tmp;

    if (!(res = ft_memalloc(1)))
        return (-1);
    while ((ret = read(fd, buff, BUFF_SIZE)))
    {
        if (ret < 0)
            return (-1);
        buff[ret] = '\0';
        if (!(tmp = ft_strjoin(res, buff)))
            return (-1);
        ft_strdel(&res);
        res = tmp;
    }
    return (input_check(res));
}
