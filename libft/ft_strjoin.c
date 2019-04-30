/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:19:54 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/23 18:51:30 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (s1 && s2 && ft_strlen(s2) != (size_t)(-1) && \
			(size_t)(-1) - ft_strlen(s1) >= ft_strlen(s2) + 1)
	{
		s = (char *)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s)
			return (NULL);
		i = -1;
		while (s1[++i])
			s[i] = s1[i];
		j = -1;
		while (s2[++j])
			s[i + j] = s2[j];
		s[i + j] = '\0';
		return (s);
	}
	return (NULL);
}
