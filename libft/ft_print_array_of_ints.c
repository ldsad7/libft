/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_of_ints.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:21:22 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/29 16:26:52 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_of_ints(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(arr[i]);
		ft_putchar('\n');
		i++;
	}
}
