/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:41:41 by tsimonis          #+#    #+#             */
/*   Updated: 2018/11/30 02:37:49 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_write(char **str, int n, int i, int fl)
{
	int		digit;

	if (fl == 1)
		(*str)[0] = '-';
	if (n == 0 && i == (fl == 1))
	{
		(*str)[i] = '0';
		return ;
	}
	if (n == 0)
		return ;
	digit = n % 10;
	ft_write(str, (int)(n / 10), i - 1, fl);
	(*str)[i] = '0' + digit;
}

static char		*overflow(void)
{
	int		n;
	char	*str;

	n = 11;
	str = (char *)malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		fl;
	size_t	len;
	int		tmp;
	char	*str;

	fl = 0;
	if (n == -2147483648)
		return (overflow());
	fl = (n < 0);
	n = n - 2 * n * (n < 0);
	tmp = n;
	len = 1;
	while (tmp / 10)
	{
		len++;
		tmp /= 10;
	}
	str = (char *)malloc(sizeof(*str) * (len + (fl == 1) + 1));
	if (!str)
		return (NULL);
	ft_write(&str, n, len + (fl == 1) - 1, fl);
	str[len + (fl == 1)] = '\0';
	return (str);
}
