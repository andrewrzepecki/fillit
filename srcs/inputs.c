/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:28:20 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/23 18:06:12 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  check_line(char *line)
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
