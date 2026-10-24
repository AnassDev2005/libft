/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:04:18 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/20 12:07:21 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	dst1[10] = "Hello";
	char	dst2[10] = "xxxxxxxxx";

	printf("strlcat return: %zu\n", ft_strlcat(dst1, "World", 10));
	printf("strlcat result: %s\n", dst1);
	printf("strlcpy return: %zu\n", ft_strlcpy(dst2, "1337School", 5));
	printf("strlcpy result: %s\n", dst2);
	return (0);
}
