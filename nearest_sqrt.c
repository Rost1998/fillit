/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:42:07 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/13 14:42:08 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

int	nearest_sqrt(int a)
{
	int		num;

	num = 1;
	while (ft_pow(num, 2) < a)
		num++;
	return (num);
}