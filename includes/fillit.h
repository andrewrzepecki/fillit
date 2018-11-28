/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:22:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/28 11:43:18 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct		s_tetri
{
	char			**tetrimino;
	int				index;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*lst_new(char **tetri, int index);
void				lst_add_back(t_tetri **lst, t_tetri *new);
void				lst_iter(t_tetri *lst, void (*f)(t_tetri *ielem));
void				ft_tabprint(char **tab);
void				tab_free(char **tab);
char				**tab_cpy(char **tab);
int					ft_print_errors(int ac, int fd, int ret);
int					set_tetris(char **tetris, t_tetri **lst, int index);
int					read_file(int fd, char *line, char **tetris, t_tetri **lst);
int					get_start(char **tetris);
int					get_end(char **tetris);
int					get_beg(char **tetris);
char				**fillit_solver(t_tetri **lst);
int					check_tetris(char **tetris);
size_t				ft_lstlen(t_tetri *lst);
void				tab_free(char **tab);
int					ft_sqrt_sup(int n);
void				ft_print_solution(char **solution);

#endif
