/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:46:52 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				len;
	unsigned int	magnitude;

	len = num_len(n);
	num = malloc(len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	magnitude = (unsigned int)n;
	if (n < 0)
		magnitude = 0u - magnitude;
	if (n == 0)
		num[0] = '0';
	while (magnitude != 0)
	{
		num[--len] = magnitude % 10 + '0';
		magnitude /= 10;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}
