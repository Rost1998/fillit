/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:40:56 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/17 11:28:44 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

static void		put_index(t_elem *lst, int p, int index)
{
	if (p == 1)
		lst->x1 = index;
	if (p == 2)
		lst->x2 = index;
	if (p == 3)
		lst->x3 = index;
	if (p == 4)
		lst->x4 = index;
}

static void		putnumlst(char *tetr, t_elem *lst, int n)
{
	int		i;
	int		p;
	int		index;
	int		tmp;

	i = 0;
	p = 0;
	while (tetr[i])
	{
		if (tetr[i] == '#')
		{
			index = i;
			tmp = i / 5;
			while (tmp--)
				index += (n - 4);
			p++;
			put_index(lst, p, index);
		}
		i++;
	}
}

static int		min(char *tetr, int n, int flag)
{
	int		i;
	int		tmp;
	int		index;
	int		minup;
	int		minleft;

	minup = -1;
	minleft = n;
	i = -1;
	while (tetr[++i])
	{
		if (tetr[i] == '#')
		{
			index = i;
			tmp = i / 5;
			while (tmp--)
				index += (n - 4);
			minup == -1 ? (minup = index) : 0;
			(i % 5) < (minleft % (n + 1)) ? (minleft = index) : 0;
		}
	}
	if (flag == 1)
		return (minleft);
	return (minup);
}

t_elem			*coordinates(char *tetr, int n)
{
	int		minup;
	int		minleft;
	t_elem	*lst;

	lst = structnew();
	putnumlst(tetr, lst, n);
	minup = min(tetr, n, 0) / (n + 1);
	while (minup--)
	{
		lst->x1 -= (n + 1);
		lst->x2 -= (n + 1);
		lst->x3 -= (n + 1);
		lst->x4 -= (n + 1);
	}
	minleft = min(tetr, n, 1) % (n + 1);
	while (minleft--)
	{
		lst->x1 -= 1;
		lst->x2 -= 1;
		lst->x3 -= 1;
		lst->x4 -= 1;
	}
	return (lst);
}
