/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array_of_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:16:14 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/17 13:50:08 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

t_elem		**fill_array_of_struct(char **tetr, int n)
{
	t_elem	**tetrs;
	t_elem	**st;

	if (!(tetrs = (t_elem**)ft_memalloc((arrlen(tetr) + 1) * sizeof(t_elem*))))
		return (0);
	st = tetrs;
	while (*tetr)
		*tetrs++ = coordinates(*tetr++, n);
	return (st);
}
