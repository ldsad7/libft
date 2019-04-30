/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 04:01:54 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/30 02:40:35 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_write(int n, int fl)
{
	int		digit;

	if (n == 0 && fl == 0)
	{
		ft_putchar('0');
		return ;
	}
	else if (n == 0)
		return ;
	fl = 1;
	digit = n % 10;
	ft_write((int)(n / 10), fl);
	ft_putchar('0' + digit);
}

void			ft_putnbr(int n)
{
	int		fl;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	fl = 0;
	ft_write(n, fl);
}
