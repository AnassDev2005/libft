/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:10:05 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/20 12:56:55 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("Bits per byte: %d\n", CHAR_BIT);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("SCHAR_MAX: %d\n", SCHAR_MAX);
	printf("UCHAR_MAX: %u\n", UCHAR_MAX);
	return (0);
}
