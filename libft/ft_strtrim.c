/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:26:39 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/30 02:37:20 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t	before;
	size_t	after;
	size_t	i;
	char	*str;

	if (s)
	{
		before = 0;
		while (s[before] == ' ' || s[before] == '\n' || s[before] == '\t')
			before++;
		after = ft_strlen(s) > 0 ? ft_strlen(s) - 1 : 0;
		while ((s[after] == ' ' || s[after] == '\n' || s[after] == '\t') &&\
				after > before)
			after--;
		str = (char *)malloc(sizeof(*str) * (after - before +\
							2 - (ft_strlen(s) == 0)));
		if (!str)
			return (NULL);
		i = -1;
		while (++i < after - before + 1 - (ft_strlen(s) == 0))
			str[i] = s[before + i];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
