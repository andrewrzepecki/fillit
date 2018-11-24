/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:02:12 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/24 01:07:32 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     char_count(char *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (s)
    {
        while (s[i])
        {
            if (s[i] == c)
                count++;
            i++;
        }
    }
    return (count);
}
