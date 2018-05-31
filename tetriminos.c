/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:47:33 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/21 11:15:38 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

static char	*create_tetriminos(char **tetr, char *buff, int *i)
{
	char	*st;

	if (!(*tetr = (char*)ft_memalloc(21 * sizeof(char))))
		return (0);
	st = *tetr;
	while ((*i + 1) % 21 && buff[*i])
		*(*tetr)++ = buff[(*i)++];
	*tetr = 0;
	*tetr = st;
	return (st);
}

static int	check_folder(int check)
{
	if (check == -1)
		ft_error();
	return (1);
}

char		**tetriminos(int fd)
{
	char	buff[1024];
	char	**tetr;
	char	**st;
	int		i;
	int		check;

	i = 0;
	while ((check = read(fd, &buff[i], 1)) && check_folder(check))
		i++;
	buff[i] = 0;
	if (!(tetr = (char**)ft_memalloc((checker_of_size(buff) + 1)\
										* sizeof(char*))))
		return (0);
	st = tetr;
	i = -1;
	while (buff[++i] != 0)
	{
		if (buff[i] != '\n')
		{
			*tetr = create_tetriminos(tetr, buff, &i);
			check_amount(*tetr++);
		}
	}
	checker_of_tetriminos(st);
	return (st);
}
