# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:49:56 by eschussl          #+#    #+#              #
#    Updated: 2024/08/09 17:22:31 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 	HarlFilter

CC 			=		c++
CFLAGS		=		-Wall -Wextra -Werror -std=c++98 -g

SRCS		=		main.cpp\
					Harl.cpp\

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
	