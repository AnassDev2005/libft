/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:42:32 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/24 18:34:19 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;
	size_t				i;

	p = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if ((size_t)p >(size_t)s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			p[i] = s[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			p[i] = s[i];
			i++;
		}
	}
	return (dest);
}
char str[] = "abcd";
char str2[] = "efg";
