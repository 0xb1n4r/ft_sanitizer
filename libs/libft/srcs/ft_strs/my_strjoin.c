//
// Created by Hajar Sabir on 2/19/22.
//

#include <libfm.h>

char	*fm_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = fm_strlen(s1);
	j = fm_strlen(s2);
	str = malloc(((i + j) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*my_strjoin(char *s1, char *s2, int ft)
{
	char	*res;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	s1_len = fm_strlen(s1);
	s2_len = fm_strlen(s2);
	res = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	if (ft == 1 || ft == 3)
		free(s1);
	j = 0;
	while (j < s2_len)
		res[i++] = s2[j++];
	if (ft == 2 || ft == 3)
		free(s2);
	res[i] = 0;
	return (res);
}

char	*fm_strdup(const char *s1)
{
	size_t	slen;
	char	*copy;

	slen = fm_strlen(s1);
	copy = malloc(sizeof(char) * (slen + 1));
	if (!copy)
		return (NULL);
	slen = 0;
	while (s1[slen])
	{
		copy[slen] = s1[slen];
		slen++;
	}
	copy[slen] = '\0';
	return (copy);
}

char	*fm_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)fm_strlen(s))
		return (fm_strdup(""));
	i = fm_strlen(s + start);
	if (i < len)
		len = i;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	fm_strlcpy(p, s + start, len + 1);
	return (p);
}