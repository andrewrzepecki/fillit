/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:10:28 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/28 16:26:40 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_print_errors(int ac, int fd, int ret)
{
	if (ac != 2 || fd < 0)
	{
		ft_putstr_fd("usage: ./fillit [file]\n", 2);
		return (1);
	}
	else if (ret == -1)
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	else
		return (0);
}

void	ft_print_solution(char **solution)
{
	int i;

	i = 0;
	while (solution[i])
	{
		ft_putendl(solution[i]);
		i++;
	}
	tab_free(solution);
	free(solution);
}
