/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 04:22:37 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/28 05:09:05 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_write(int n, int fl, int fd)
{
	int		digit;

	if (n == 0 && fl == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n == 0)
		return ;
	fl = 1;
	digit = n % 10;
	ft_write((int)(n / 10), fl, fd);
	ft_putchar_fd('0' + digit, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		fl;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	fl = 0;
	ft_write(n, fl, fd);
}
