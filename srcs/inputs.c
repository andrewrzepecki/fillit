/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/22 13:41:32 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         read_file(int fd, char **content)
{
    int     ret;
    char    buff[BUFF_SIZE + 1];
    char    *tmp;

    while ((ret = read(fd, buff, BUFF_SIZE)))
    {
        if (ret < 0)
            return (-1);
        buff[ret] = '\0';
        if (!tmp)
            if (!(tmp = (char*)ft_memalloc(1)))
               return (-1);
        while
        if ((res = 

    }
}
