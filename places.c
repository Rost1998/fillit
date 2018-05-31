/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:11:07 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/19 10:11:08 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"
#define MAX ((n + 1) * n - 1)

int		check_place(char *field, t_elem *elem)
{
	if (field[elem->x1] != '.')
		return (0);
	if (field[elem->x2] != '.')
		return (0);
	if (field[elem->x3] != '.')
		return (0);
	if (field[elem->x4] != '.')
		return (0);
	return (1);
}

int		check_borders_right(char *field, t_elem *elem)
{
	if (field[elem->x1] == '\n' ||
		field[elem->x2] == '\n' ||
		field[elem->x3] == '\n' ||
		field[elem->x4] == '\n')
		return (0);
	return (1);
}

int		check_borders_down(t_elem *elem, int n)
{
	if (elem->x1 > MAX ||
		elem->x2 > MAX ||
		elem->x3 > MAX ||
		elem->x4 > MAX)
		return (0);
	return (1);
}

void	back_to_border(t_elem *lst, int n)
{
	while ((lst->x1 % (n + 1)) &&
			(lst->x2 % (n + 1)) &&
			(lst->x3 % (n + 1)) &&
			(lst->x4 % (n + 1)))
	{
		(lst->x1)--;
		(lst->x2)--;
		(lst->x3)--;
		(lst->x4)--;
	}
}
