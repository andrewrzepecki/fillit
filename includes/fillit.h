/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:35:43 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/26 18:41:12 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

typedef struct		s_tetri
{
	char			**tetrimino;
	int				index;
	struct s_tetri	*next;
}					t_tetri;

t_tetri	*lst_new(char **tetri, int index);
void    lst_add_back(t_tetri **lst, t_tetri *new);
void    lst_iter(t_tetri *lst, void (*f)(t_tetri *ielem));
void    print_node(t_tetri *lst);
void	tab_free(char **tab);
char	**tab_cpy(char **tab);
int     ft_print_errors(int ac, int fd, int ret);
int		set_tetris(char **tetris, t_tetri **lst, int index);
int     read_file(int fd, char *line, char **tetris, t_tetri **lst);
int		fillit_solver(t_tetri **lst);

#endif
