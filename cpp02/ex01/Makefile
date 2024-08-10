# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:49:56 by eschussl          #+#    #+#              #
#    Updated: 2024/08/10 14:56:46 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 	Fixed-point

CC 			=		c++
CFLAGS		=		-Wall -Wextra -Werror -std=c++98 -g

SRCS		=		main.cpp\
					Fixed.cpp\

OBJS		=		$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
	