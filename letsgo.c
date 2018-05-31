/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:40:24 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/17 12:07:41 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

static int	fieldlen(char *field)
{
	int		i;

	i = 0;
	while (field[i] != '\n')
		i++;
	return (i);
}

int			letsgo(char *field, t_elem **lst, char **tetr, int i)
{
	while (check_borders_down(*lst, fieldlen(field)))
	{
		if (check_place(field, *lst))
		{
			set_coord(field, *lst, i);
			if (!lst[1])
				return (1);
			if (!letsgo(field, &lst[1], &tetr[1], i + 1))
			{
				reset_coord(field, *lst);
				reset_tetr(lst[1], tetr[1], fieldlen(field));
			}
			else
				return (1);
		}
		increment_right(*lst);
		if (!check_borders_right(field, *lst))
		{
			back_to_border(*lst, fieldlen(field));
			increment_down(*lst, fieldlen(field));
		}
	}
	return (0);
}
