#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total1;
	size_t	total2;
	size_t	i;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	total1 = ft_strlen(s1);
	total2 = ft_strlen(s2);
	s = malloc(total1 + total2 + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < total1)
		s[i++] = s1[i - 1];
	while (i < total1 + total2)
	{
		s[i] = s2[i - total1];
		i++;
	}
	s[i] = '\0';
	return (s);
}
