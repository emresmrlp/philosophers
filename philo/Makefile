# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 17:45:17 by ysumeral          #+#    #+#              #
#    Updated: 2025/08/16 23:56:40 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
INC_DIR = ./include
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/memory.c \
	$(SRC_DIR)/parse.c \
	$(SRC_DIR)/state.c \
	$(SRC_DIR)/util.c \
	$(SRC_DIR)/action.c \
	$(SRC_DIR)/simulation.c
OBJ = $(SRC:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re