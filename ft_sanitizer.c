//
// Created by Hajar Sabir on 2/19/22.
//


#include "ft_sanitizer.h"
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
		tmp->filename = malloc(ft_strlen(file)+1);
		ft_strcpy(tmp->filename, file);
		tmp->line = line;
		tmp->next = NULL;
		head->next = tmp;
	}
	else
		ft_printf(1, "FATAL: memory allocation failed\n");
}

void remove_from_list(void *p, char *s, int line, t_info *head)
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
		ft_printf(1, "No leak detected :)\n");
	else
	{
		ft_printf(1, "Leaks summary\n");
		while (head != NULL)
		{
//			ft_printf(1,"%d byte(s) has been leaked at the address %p in the %s at the line %d\n",
//					  head->len, head->ptr, head->filename, head->line);
			ft_printf(1, "------------------------------------------\n");
			ft_printf(1, "address : %p\n", head->ptr);
			ft_printf(1, "size    : %d\n", head->len);
			ft_printf(1, "file    : %s\n", head->filename);
			ft_printf(1, "line    : %d\n", head->line);
			ft_printf(1, "------------------------------------------\n");
			head = head->next;
		}
	}
}

int main(void)
{
	t_info	head;
//	char *log = argv[1];
//	int fd;
	int i;
	char *buffer;
	void *ptr;
	char file[128];
	int line;
	int len;


	head.ptr = NULL;
	head.next = NULL;
	buffer = get_next_line(0);
	while (buffer)
	{
		if (buffer[0] == 'M') {
			if ((i = sscanf(buffer, "M %d %p %s %d\n", &len, &ptr, file, &line)) == 4)
				add_to_list(len, ptr, file, line, &head);
			else
				ft_printf(1, "Error: garbage in the EOL: %s: %d\n", buffer, i);
		}
		else if (buffer[0] == 'F')
		{
			if ((i = sscanf(buffer, "F %p %s %d\n", &ptr, file, &line)) == 3)
				remove_from_list(ptr, file, line, &head);
			else
				ft_printf(1, "Error: garbage in the EOF: %s: %d\n", buffer, i);
		}
		else
			ft_printf(1, "Error: Garbage in the log\n");
		buffer = get_next_line(0);
	}
	print_leaks(&head);
	free(buffer);
}
