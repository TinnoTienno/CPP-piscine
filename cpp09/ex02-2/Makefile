# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noda <noda@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:05:09 by eschussl          #+#    #+#              #
#    Updated: 2025/02/07 14:43:07 by noda             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe$(EXTENSION)

EXTENSION	=	.bin
CC 			=	c++ 
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror -g
SRCS		=	main.cpp PmergeMe.cpp PmergeMeList.cpp PmergeMeVec.cpp Utils.cpp ListIterator.cpp MainIterator.cpp PendIterator.cpp\
				
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
