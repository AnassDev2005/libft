/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:37:33 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/22 12:48:18 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* void	change(unsigned int i, char *c) */
/* { */
/* 	if (i % 2 == 0) */
/* 		*c = 'X'; */
/* } */
/* int main(){ */
/*     char s[] = "hello"; */
/*     ft_striteri(s , change); */
/*     printf("%s" , s); */
/* } */
