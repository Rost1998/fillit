/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:31:59 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/17 13:49:34 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLITLIB_H
# define FILLITLIB_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_mylist
{
	int				x1;
	int				x2;
	int				x3;
	int				x4;
}					t_elem;

void				reset_coord(char *field, t_elem *lst);
void				back_to_border(t_elem *lst, int n);
void				increment_down(t_elem *lst, int n);
void				increment_right(t_elem *lst);
void				set_coord(char *field, t_elem *lst, int i);
void				reset_tetr(t_elem *elem, char *tetr, int n);
int					letsgo(char *field, t_elem **lst, char **tetr, int i);
int					check_borders_right(char *field, t_elem *elem);
int					check_borders_down(t_elem *elem, int n);
int					check_place(char *field, t_elem *elem);
t_elem				**fill_array_of_struct(char **tetr, int n);
t_elem				*coordinates(char *tetr, int n);
int					nearest_sqrt(int a);
int					arrlen(char **arr);
char				*fill_array(int fd);
void				usage(void);
void				ft_error(void);
char				**tetriminos(int fd);
int					checker_of_size(char *buff);
void				checker_of_tetriminos(char **b);
void				check_amount(char *b);
t_elem				*structnew(void);

#endif
