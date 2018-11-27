/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:32:16 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/27 19:32:55 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Fichier pour afficher a l'ecran 
// ->> print_errors: analyse des valeurs de retour de read, open et des arguments.
// ->> print_solution: affichage de la solution si print_errors renvoi 0.

int         ft_print_errors(int ac, int fd, int ret)
{
    if (ac != 2 || fd < 0)
    {
        ft_putstr_fd("usage: ./fillit source_file\n", 0);
        return (1);
    }
    else if (ret == -1)
    {
        ft_putstr_fd("error\n", 0);
        return (1);
    }
    else
        return (0);
}

void			ft_tabprint(char **tab)
{
	int x;

	x = 0;
	while (tab[x])
	{
		ft_putendl(tab[x]);
		x++;
	}
}

void        ft_print_solution(char **solution)
{
	int i;

	i = 0;
	while (solution[i])
	{
		ft_putendl(solution[i]);
		i++;
	}
}
