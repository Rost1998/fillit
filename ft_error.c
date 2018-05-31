/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:09:22 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/09 12:42:52 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

void	usage(void)
{
	ft_putstr("usage: [destination]fillit <tetriminos_file>\n");
	exit(-1);
}
