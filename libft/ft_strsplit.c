/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:09:42 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/05 15:35:31 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_words(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == c || s[1] == '\0'))
			i++;
		s++;
	}
	return (i);
}

static int	len_letters(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		i;
	int		ii;

	if (!s || !(strings = (char**)malloc((len_words(s, c) + 1) * 8)))
		return (0);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (!(strings[i] = (char*)malloc(len_letters(s, c) + 1)))
				return (0);
			ii = 0;
			while (*s != c && *s != '\0')
				strings[i][ii++] = *s++;
			strings[i++][ii] = '\0';
		}
		if (*s)
			s++;
	}
	strings[i] = 0;
	return (strings);
}
