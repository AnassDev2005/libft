/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:34:22 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

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

static char	**free_all(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

static char	*copy_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static char	**fill_words(char **words, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			words[i] = copy_word(s, c);
			if (!words[i])
				return (free_all(words, i));
			s += ft_strlen(words[i]);
			i++;
		}
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**words;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (count >= (size_t)-1 / sizeof(*words))
		return (NULL);
	words = malloc(sizeof(*words) * (count + 1));
	if (!words)
		return (NULL);
	return (fill_words(words, s, c));
}
