/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:54:16 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/09 14:00:03 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	char	x;
	size_t	i;

	tmp = b;
	x = (unsigned char)c;
	i = 0;
	while (len--)
		tmp[i++] = x;
	return (b);
}
