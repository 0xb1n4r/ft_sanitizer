//
// Created by Hajar Sabir on 2/19/22.
//


#include "fpurify.h"
#include <fcntl.h>

#ifndef NULL
# define NULL (void *)0
#endif

void add_to_list(int len, void *p, char *file, int line, t_info *head)
{
	t_info	*tmp;

	while (head->next != NULL)
		head = head->next;
	if ((tmp = malloc(sizeof(t_info))) != NULL)
	{
		tmp->len = len;
		tmp->ptr = p;
		tmp->filename = malloc(strlen(file)+1);
		strcpy(tmp->filename, file);
		tmp->line = line;
		tmp->next = NULL;
		head->next = tmp;
	}
	else
		printf("FATAL: memory allocation failed\n");
}

void remove_from_list(void *p, t_info *head)
{
	t_info	*tmp;

	while (head->next != NULL)
	{
		if (head->next->ptr == p)
		{
			tmp = head->next;
			head->next = head->next->next;
			free(tmp->filename);
			free(tmp);
		}
		else
			head = head->next;
	}
}

void print_leaks(t_info *head)
{
	head = head->next;
	if (head == NULL)
		printf("No leak detected :)\n");
	else
	{
		printf("Leaks summary\n");
		while (head != NULL)
		{
//			ft_printf(1,"%d byte(s) has been leaked at the address %p in the %s at the line %d\n",
//					  head->len, head->ptr, head->filename, head->line);
			printf("----------------------------------\n");
			printf("address : %p\n", head->ptr);
			printf("size    : %d\n", head->len);
			printf("file    : %s\n", head->filename);
			printf("line    : %zu\n", head->line);
			printf("---------------------------------\n");
			head = head->next;
		}
	}
}

int main(void)
{
	t_info	head;
	char	*log = argv[1];
	int		fd;
	int		i;
	char	*buffer = NULL;
	void	*ptr;
	char	file[128];
	int		line;
	int		len;

	head.ptr = NULL;
	head.next = NULL;
	buffer = r_line(RFD);
	while (buffer)
	{
		printf("Buffer -> %s\n", buffer);
		buffer = r_line(RFD);

		if (buffer[0] == 'M') {
			if ((i = sscanf(buffer, "M %d %p %s %d\n", &len, &ptr, file, &line)) == 4)
				add_to_list(len, ptr, file, line, &head);
			else
				printf("Error: garbage in the EOL: %s: %d\n", buffer, i);
		}
		else if (buffer[0] == 'F')
		{
			if ((i = sscanf(buffer, "F %p %s %d\n", &ptr, file, &line)) == 3)
				remove_from_list(ptr, &head);
			else
				printf("Error: garbage in the EOF: %s: %d\n", buffer, i);
		}
		else
			printf("Error: Garbage in the log\n");
	}
	print_leaks(&head);
	free(buffer);
}
