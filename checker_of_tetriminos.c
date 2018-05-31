/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_of_tetriminos2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:01:01 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/19 10:43:38 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

static int	check_selection(char *b, int i)
{
	int		n;

	n = 0;
	if (b[i + 1] == '#')
		n++;
	if (b[i - 1] == '#' && i % 5)
		n++;
	if (b[i - 5] == '#' && i > 4)
		n++;
	if (b[i + 5] == '#' && i < 14)
		n++;
	return (n);
}

static int	next(char *b, int i, int prev)
{
	int		n;

	n = 0;
	if (b[i + 1] == '#' && i + 1 != prev)
		n++;
	if (b[i - 1] == '#' && i % 5 && i - 1 != prev)
		n++;
	if (b[i - 5] == '#' && i > 4 && i - 5 != prev)
		n++;
	if (b[i + 5] == '#' && i < 14 && i + 5 != prev)
		n++;
	return (n);
}

static int	check_valid(char *b, int prev, int i, int amount)
{
	if (b[i + 1] == '#' && (i + 1) != prev && amount < 4)
		return (check_valid(b, i, i + 1, amount + next(b, i, prev)));
	if (b[i - 1] == '#' && (i - 1) != prev && i % 5 && amount < 4)
		return (check_valid(b, i, i - 1, amount + next(b, i, prev)));
	if (b[i + 5] == '#' && (i + 5) != prev && i < 14 && amount < 4)
		return (check_valid(b, i, i + 5, amount + next(b, i, prev)));
	if (b[i - 5] == '#' && (i - 5) != prev && i > 4 && amount < 4)
		return (check_valid(b, i, i - 5, amount + next(b, i, prev)));
	if (amount == 4)
		return (1);
	else
		return (0);
}

void		checker_of_tetriminos(char **b)
{
	int		i;

	while (*b)
	{
		i = 0;
		while ((*b)[i] != '\0')
		{
			if ((*b)[i] == '#' && check_selection(*b, i) == 0)
				ft_error();
			if ((*b)[i] == '#' && check_selection(*b, i) == 1)
			{
				if (!check_valid(*b, -1, i, 1))
					ft_error();
				else
					break ;
			}
			i++;
		}
		b++;
	}
}
