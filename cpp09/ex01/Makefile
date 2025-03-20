# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:05:09 by eschussl          #+#    #+#              #
#    Updated: 2025/03/20 14:44:03 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RPN

CC 			=	c++ 
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror -g
SRCS		=	main.cpp RPN.cpp
				
OBJS		=	$(addprefix .obj/,$(SRCS:.cpp=.o))

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -Iinc

.obj/%.o: src/%.cpp
	@mkdir -p .obj
	@mkdir -p .obj/$(ABS_PATH)
	@mkdir -p .obj/$(CON_PATH)
	@mkdir -p .obj/$(INT_PATH)
	$(CC) -MMD $(CFLAGS) -c $< -o $@ -Iinc

clean :
	@rm -rf .obj

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

-include $(OBJS:.o=.d)
