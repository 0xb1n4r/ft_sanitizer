/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:41:24 by hsabir            #+#    #+#             */
/*   Updated: 2022/02/19 11:42:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRS_H
# define FT_STRS_H

# include <stddef.h>
# include <stdlib.h>

char	**fm_split(char const *s, char c);
char	*fm_strchr(const char *s, int c);
char	*fm_strdup(const char *s1);
void	fm_striteri(char *s, void (*f)(unsigned int, char *));
char	*fm_strjoin(char const *s1, char const *s2);
char	*my_strjoin(char *s1, char *s2, int ft);
size_t	fm_strlcat(char *dst, const char *src, size_t size);
size_t	fm_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	fm_strlen(const char *s);
char	*fm_strmapi(char const *s, char (*f)(unsigned int, char));
int		fm_strncmp(const char *s1, const char *s2, size_t n);
char	*fm_strrchr(const char *s, int c);
char	*fm_strtrim(char const *s1, char const *set);
char	*fm_strnstr(const char *hazstack, const char *needle, size_t len);
char	*fm_substr(char const *s, unsigned int start, size_t len);
int		fm_putstr(char *s);
//size_t	fm_strlen(const char *s);
//size_t	fm_strlcpy(char *dst, const char *src, size_t dstsize);
char 	*fm_strcpy(char *dest, char *src);

#endif
