# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:19:51 by ysumeral          #+#    #+#              #
#    Updated: 2025/05/09 20:19:00 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
INC_DIR = ./include
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/dinner.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/memory.c \
	$(SRC_DIR)/utils.c
OBJ = $(SRC:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

test: all clean # bu komut proje bitiminde kaldırılmalı, .o dosyalarını temizler.

re: fclean all

.PHONY: all clean fclean re