/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:21:33 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/19 10:48:31 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

void		set_coord(char *field, t_elem *lst, int i)
{
	char	*alphabet;

	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	field[lst->x1] = alphabet[i];
	field[lst->x2] = alphabet[i];
	field[lst->x3] = alphabet[i];
	field[lst->x4] = alphabet[i];
}

void		reset_coord(char *field, t_elem *lst)
{
	field[lst->x1] = '.';
	field[lst->x2] = '.';
	field[lst->x3] = '.';
	field[lst->x4] = '.';
}

void		reset_tetr(t_elem *elem, char *tetr, int n)
{
	t_elem	*tmp;

	tmp = coordinates(tetr, n);
	elem->x1 = tmp->x1;
	elem->x2 = tmp->x2;
	elem->x3 = tmp->x3;
	elem->x4 = tmp->x4;
	free(tmp);
}
