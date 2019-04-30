/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_ints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:25:50 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/29 16:25:55 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		memalloc(char const *s, char c, int *result, size_t rows)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	k = 0;
	while (++i < rows)
	{
		j = k;
		while (s[j] == c)
			j++;
		k = j;
		while (s[k] != c && s[k])
			k++;
		result[i] = ft_atoi(s + j);
	}
}

int				*ft_strsplit_to_ints(char const *s, char c)
{
	int		*result;
	size_t	rows;
	size_t	i;
	int		fl;

	rows = 0;
	fl = 0;
	i = -1;
	if (s)
	{
		while (s[++i])
		{
			if (++rows && s[i] == c && fl == 1)
				fl = 0;
			else if (--rows + 1 && s[i] != c)
				fl = 1;
		}
	}
	rows += fl;
	result = (int *)malloc(sizeof(*result) * rows);
	if (!result)
		return (NULL);
	memalloc(s, c, result, rows);
	return (result);
}
