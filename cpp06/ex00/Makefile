# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:05:09 by eschussl          #+#    #+#              #
#    Updated: 2024/11/05 18:43:15 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Converter

CC 			=	c++ 
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror -g
ABS_PATH	=	Abstracts/
CON_PATH	=	Concretes/
INT_PATH	=	interfaces/
SRCS		=	main.cpp \
				$(addprefix $(ABS_PATH), ScalarConvert.cpp)\
				
OBJS		=	$(addprefix .obj/,$(SRCS:.cpp=.o))

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -Iinc/Abstracts -Iinc/Concretes -Iinc/Interfaces/

.obj/%.o: src/%.cpp
	@mkdir -p .obj
	@mkdir -p .obj/$(ABS_PATH)
	@mkdir -p .obj/$(CON_PATH)
	@mkdir -p .obj/$(INT_PATH)
	$(CC) -MMD $(CFLAGS) -c $< -o $@ -Iinc/Abstracts -Iinc/Concretes -Iinc/Interfaces/

clean :
	@rm -rf .obj

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

-include $(OBJS:.o=.d)
