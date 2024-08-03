# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:49:56 by eschussl          #+#    #+#              #
#    Updated: 2024/07/26 12:24:08 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Brainz

CC 			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

SRCS		=		main.cpp\
					newZombie.cpp\
					randomChump.cpp\
					Zombie.cpp\

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
	