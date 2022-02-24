#include "libfm.h"

int main(void)
{
	int *ptr = malloc_ft(10);
	char *str = malloc_ft(10);
	free_ft(ptr);
	free_ft(str);
}
