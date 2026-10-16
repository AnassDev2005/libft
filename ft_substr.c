#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;
	size_t	total;

	if (!s)
		return (NULL);
	total = ft_strlen(s);
	if (start >= total)
		len = 0;
	else if (len > total - start)
		len = total - start;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
