/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:46:52 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/26 09:44:32 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	ln;

	ln = (long)n;
	len = num_len(ln);
	num = malloc(len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (ln == 0)
		num[0] = '0';
	if (ln < 0)
	{
		num[0] = '-';
		ln = -ln;
	}
	while (ln > 0)
	{
		num[--len] = (ln % 10) + '0';
		ln /= 10;
	}
	return (num);
}
