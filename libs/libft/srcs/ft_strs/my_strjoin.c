//
// Created by Hajar Sabir on 2/19/22.
//

#include "libft.h"

char	*my_strjoin(char *s1, char *s2, int ft)
{
	char	*res;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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