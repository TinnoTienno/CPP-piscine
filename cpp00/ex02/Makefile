# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:49:56 by eschussl          #+#    #+#              #
#    Updated: 2024/10/21 16:56:06 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 Phonebook

CC 			=	c++
CFLAGS		=	 -Wall -Wextra -Werror -std=c++98 -g 
SRCS		=	Phonebook.cpp Contact.cpp main.cpp

OBJS		=	$(addprefix .obj/,$(SRCS:.cpp=.o))

all : $(NAME)
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -Iinc/

.obj/%.o: src/%.cpp
	@mkdir -p .obj
	$(CC) -MMD $(CFLAGS) -c $< -o $@ -Iinc/

clean :
	@rm -rf .obj

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)
	
	