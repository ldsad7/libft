/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:51:29 by tsimonis          #+#    #+#             */
/*   Updated: 2019/01/08 15:23:55 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *tmp, size_t size)
{
	free(tmp);
	tmp = NULL;
	size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*tmp;

	result = NULL;
	if (lst && f)
	{
		if (!result)
			return (NULL);
		result = f(lst);
		if (lst->next)
		{
			tmp = ft_lstmap(lst->next, f);
			if (tmp)
				result->next = tmp;
			else
			{
				ft_lstdelone(&result, &del);
				return (NULL);
			}
		}
		return (result);
	}
	return (lst);
}
