# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 00:07:31 by pleblond          #+#    #+#              #
#    Updated: 2025/01/30 00:07:31 by pleblond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE)
INCLUDE = -I includes -I libft
RM = rm -f

LIB = libft
LIBFT = $(LIB)/libft.a

SRC =	src/core/pipex.c \
		src/core/pipex_utils.c \

OBJ =	$(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(LIB)
			$(MAKE) -C $(LIB)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)
		$(MAKE) clean -C $(LIB)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re