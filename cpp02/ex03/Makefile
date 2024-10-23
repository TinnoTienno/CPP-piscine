# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 15:59:46 by eschussl          #+#    #+#              #
#    Updated: 2024/10/22 16:33:06 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 bsp

CC 			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g 
SRCS		=	main.cpp Fixed.cpp Point.cpp bsp.cpp

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

-include $(OBJS:.o=.d)
	