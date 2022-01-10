# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:12:10 by hsabir            #+#    #+#              #
#    Updated: 2022/01/10 18:23:03 by hsabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_sanitizer

LFT_DIR = libs/libft
LFT_NAME = libft.a

SRCS = ./srcs

CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Debugging
CFLAGS += -g3 -fsanitize=address

DBG_SCRCS = ft_sanitizer.dSYM

FILES = $(SRCS)/main.c

all : $(NAME)

$(NAME): $(LFT_NAME)
	$(CC) $(CFLAGS) $(FILES) $(LFT_NAME) -o $(NAME)

$(LFT_NAME):
	$(MAKE) all -sC $(LFT_DIR)/
	cp $(LFT_DIR)/$(LFT_NAME) $(LFT_NAME)

fclean:
	rm -f $(NAME)
	rm -f $(LFT_NAME)
	rm -rf $(DBG_SCRCS)
	$(MAKE) fclean -sC $(LFT_DIR)/

clean:
	rm -f $(LFT_NAME)
	$(MAKE) fclean -sC $(LFT_DIR)

re: fclean all
	$(MAKE) re -sC $(LFT_DIR)/

.PHONY: clean fclean all re
