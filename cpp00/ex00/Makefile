# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:49:56 by eschussl          #+#    #+#              #
#    Updated: 2024/10/21 17:45:08 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 Megaphone

CC 			=	c++
CFLAGS		=	 -Wall -Wextra -Werror -std=c++98 -g 
SRCS		=	megaphone.cpp
OBJS		=	$(addprefix .obj/,$(SRCS:.cpp=.o))


all : $(NAME)
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.obj/%.o: src/%.cpp
	mkdir -p .obj
	$(CC) -MMD $(CFLAGS) -c $< -o $@

clean :
	rm -rf .obj

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
	
-include $(OBJS:.o=.d)