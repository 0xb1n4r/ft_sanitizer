//
// Created by Hajar Sabir on 2/19/22.
//

#ifndef FT_SANITIZER_FT_LOG_H
#define FT_SANITIZER_FT_LOG_H

#include "libs/libft/incs/libft.h"
#include <stdlib.h>

void *ft_malloc_log(int len, int line, const char *filename);

void ft_free_log(void *p, const char *filename, int line);

#define malloc_ft(len) ft_malloc_log(len, __LINE__, __FILE__)
#define free_ft(p) ft_free_log(p, __FILE__, __LINE__)

#endif //FT_SANITIZER_FT_LOG_H
