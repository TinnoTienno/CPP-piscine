# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:05:09 by eschussl          #+#    #+#              #
#    Updated: 2024/10/28 20:57:11 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Materia

CC 			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g
ABS			=	Abstracts/
CON			=	Concretes/
INT			=	interfaces/
SRCS		=	main.cpp\
				$(addprefix($(CON), Character.cpp Ice.cpp MateriaSource.cpp))\
				$(addprefix($(INT), ICharacter.cpp IMateriasource.cpp))\
				$(addprefix($(ABS), AMateria.cpp))

OBJS		=	$(addprefix .obj/,$(SRCS:.cpp=.o))

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -Iinc/

.obj/%.o: src/%.cpp
	@mkdir -p .obj
	$(CC) -MMD $(CFLAGS) -c $< -o $@ -Iinc/Abstracts -Iinc/Concretes -Iinc/Interfaces/

clean :
	@rm -rf .obj

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

-include $(OBJS:.o=.d)
