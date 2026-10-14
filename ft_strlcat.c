#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = 0;
	while (dstlen < dstsize && dest[dstlen] != '\0')
		dstlen++;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	i = dstlen;
    j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dest[i] = src[j];
		i++;
        j++;
	}
	dest[i] = '\0';
	return (dstlen + srclen);
}
