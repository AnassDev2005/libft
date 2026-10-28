/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:10:53 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/28 11:11:25 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	result;
	unsigned long	limit;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	limit = (unsigned long)9223372036854775807 + (sign < 0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (result > (limit - (*nptr - '0')) / 10)
			return (-(sign == 1));
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}
