/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:16:09 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/28 11:16:21 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_count(char *s, char c)
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
