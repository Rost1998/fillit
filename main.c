/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:17:26 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/17 14:04:16 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

static void	new_coord(t_elem **lst, char **tetrs, int n)
{
	int		i;

	i = -1;
	while (lst[++i])
		reset_tetr(lst[i], tetrs[i], n);
}

static void	print_field(char *field)
{
	int		i;

	i = 0;
	while (field[i])
		ft_putchar(field[i++]);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	**tetrs;
	char	*field;
	t_elem	**tetr_structs;

	if (argc != 2)
		usage();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	tetrs = tetriminos(fd);
	n = nearest_sqrt(arrlen(tetrs) * 4);
	field = ft_field(n, n, '.');
	tetr_structs = fill_array_of_struct(tetrs, n);
	while (!letsgo(field, tetr_structs, tetrs, 0))
	{
		free(field);
		n++;
		field = ft_field(n, n, '.');
		new_coord(tetr_structs, tetrs, n);
	}
	print_field(field);
	close(fd);
	return (0);
}
