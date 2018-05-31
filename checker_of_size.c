/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_of_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:53:12 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/21 11:13:13 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"
#define CHECK1(x) (!((x + 1) % 21) || !((x + 2) % 21))
#define CHECK2(x) (!((x + 7) % 21) || !((x + 12) % 21) || !((x + 17) % 21))

int			checker_of_size(char *buff)
{
	int		i;
	int		n;
	int		tetriminoses;

	i = 0;
	n = 0;
	tetriminoses = 0;
	while (buff[i] != '\0' &&
		(buff[i] == '.' || buff[i] == '#' || buff[i] == '\n'))
	{
		if ((CHECK1(i) || CHECK2(i)) && buff[i] != '\n')
			ft_error();
		if (!buff[i + 1] && buff[i] != '\n')
			ft_error();
		if (!((i + 1) % 21) && buff[i] == '\n')
			n++;
		if (!((i + 2) % 21) && i != 0)
			tetriminoses++;
		i++;
	}
	if (buff[i] != '\0' || tetriminoses != n + 1 || tetriminoses > 26)
		ft_error();
	return (tetriminoses);
}

void		check_amount(char *b)
{
	int		i;

	i = 0;
	while (*b != '\0')
		if (*b++ == '#')
			i++;
	if (i != 4)
		ft_error();
}
