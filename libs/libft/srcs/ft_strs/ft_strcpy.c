//
// Created by Hajar Sabir on 2/19/22.
//

#include <libfm.h>

char *fm_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	fm_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	if (src != NULL)
		srcsize = fm_strlen(src);
	else if (dst != NULL)
		srcsize = fm_strlen(dst);
	while (!(dst == NULL || src == NULL)
		   && dstsize != 0 && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (srcsize);
}