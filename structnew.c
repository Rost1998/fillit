/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:06:13 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/16 18:29:47 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

t_elem	*structnew(void)
{
	t_elem	*new;

	if (!(new = (t_elem*)ft_memalloc(sizeof(t_elem))))
		return (0);
	new->x1 = -1;
	new->x2 = -1;
	new->x3 = -1;
	new->x4 = -1;
	return (new);
}
