/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 02:41:45 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/30 02:35:44 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	size_t	i;

	if (s && f)
	{
		if (ft_strlen(s) == (size_t)(-1))
			return (NULL);
		fresh = (char *)malloc(sizeof(*fresh) * (ft_strlen(s) + 1));
		if (!fresh)
			return (NULL);
		i = 0;
		while (s[i])
		{
			fresh[i] = f(i, s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return ((char *)s);
}
