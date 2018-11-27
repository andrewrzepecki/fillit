/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:58:58 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/27 15:25:18 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **tab)
{
	if (!(tab) || !(*tab))
	{
		ft_putendl("(null)");
		return ;
	}
	ft_putstr("{\n");
	while (*tab)
	{
		ft_putchar('|');
		ft_putstr(*tab);
		ft_putstr("|\n");
		tab++;
	}
	ft_putstr("}\n");
}
