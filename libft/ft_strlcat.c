/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:37:27 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/30 02:16:16 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	min;

	len = ft_strlen(dst);
	i = 0;
	while (src[i] && i + len + 1 < size)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	min = size < len ? size : len;
	return (min + ft_strlen(src));
}
