NAME = libpurify.a

SRCS_DIR = srcs/

SRC = $(shell find $(SRCS_DIR) -name '*.c')

all: $(NAME)
	
$(NAME):
	@gcc -c -Wall -Werror -Wextra -I incs/ $(SRC)
	ar -rcs $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
