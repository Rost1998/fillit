/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:03:03 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/17 11:29:04 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

void		increment_right(t_elem *lst)
{
	lst->x1++;
	lst->x2++;
	lst->x3++;
	lst->x4++;
}

void		increment_down(t_elem *lst, int n)
{
	lst->x1 += (n + 1);
	lst->x2 += (n + 1);
	lst->x3 += (n + 1);
	lst->x4 += (n + 1);
}
