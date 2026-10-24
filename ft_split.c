/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:34:22 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/22 11:45:37 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}
static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
	{
		i++;
	}
	return (i);
}
static char	**free_all(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		if (s[i] == c)
			i++;
		else
		{
			len = len_word(s + i, c);
			str[j] = ft_substr(s, i, len);
			if (!str[j])
				return (free_all(str, j));
			i += len;
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}
