/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/22 12:32:06 by andrewrze        ###   ########.fr       */
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
        if (!tmp)
            tmp = 

    }
}
