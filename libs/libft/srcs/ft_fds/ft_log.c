//
// Created by Hajar Sabir on 2/19/22.
//

//
// Created by Hajar Sabir on 2/19/22.
//

#include "../../incs/libft.h"
//#include "../libs/libft/incs/libft.h"

//#include <stdlib.h>

void *ft_malloc_log(int len, int line, const char *filename)
{
	void *ptr = malloc(len);
	ft_printf(1, "M %d %p %s %d\n",len, ptr,  filename, line);
	return ptr;
}

void ft_free_log(void *p, const char *filename, int line)
{
	ft_printf(1, "F %p %s %d\n", p, filename, line);
	free(p);
}
