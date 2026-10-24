/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:38:21 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/22 10:34:12 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]) != NULL)
	{
		end--;
	}
	str = ft_substr(s1, start, end - start);
	return (str);
}
