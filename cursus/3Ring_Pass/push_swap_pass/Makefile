# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2021/09/09 19:27:55 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

RM = rm -f

SANITIZE = -fsanitize=address -g3

LIBFT = -Llibft -lft

FILES = ft_atoi_push \
		ft_aux \
		ft_checks \
		ft_chunk \
		ft_hi_cases \
		ft_low_cases \
		ft_push \
		ft_reverse \
		ft_rotate \
		ft_swap \
		main \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(FLAGS) $^ $(LIBFT) -o $@ 

all: $(NAME)

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY: clean fclean %.o
