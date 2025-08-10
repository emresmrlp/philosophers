# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:19:51 by ysumeral          #+#    #+#              #
#    Updated: 2025/08/10 13:25:19 by ysumeral         ###   ########.fr        #
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
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/actions.c \
	$(SRC_DIR)/threads.c \
	$(SRC_DIR)/parser.c
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