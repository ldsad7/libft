/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:58:15 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/29 18:02:19 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		memalloc(char const *s, char c, t_list **result, size_t rows)
{
	size_t	i;
	size_t	j;
	size_t	k;
	t_list	*tmp1;
	t_list	*tmp2;

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
		tmp1 = ft_lstnew(s + j, k - j);
		((char *)(tmp1->content))[k - j] = '\0';
		if (i == 0)
			*result = tmp1;
		else
			tmp2->next = tmp1;
		tmp2 = tmp1;
	}
}

t_list			*ft_strsplit_to_list(char const *s, char c)
{
	t_list	*result;
	size_t	rows;
	size_t	i;
	int		fl;

	result = NULL;
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
	memalloc(s, c, &result, rows);
	return (result);
}
