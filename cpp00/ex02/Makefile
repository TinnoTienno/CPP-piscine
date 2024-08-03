# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:49:56 by eschussl          #+#    #+#              #
#    Updated: 2024/07/25 12:22:16 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 R_Ingeneering

CC 			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

SRCS		=		tests.cpp\
					Account.cpp\

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
	