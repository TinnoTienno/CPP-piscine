# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:05:09 by eschussl          #+#    #+#              #
#    Updated: 2025/01/30 16:06:04 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Forms$(EXTENSION)

EXTENSION	=	.bin
CC 			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror -g
ABS_PATH	=	Abstracts/
CON_PATH	=	Concretes/
INT_PATH	=	interfaces/
SRCS		=	main.cpp \
				$(addprefix $(ABS_PATH),AForm.cpp)\
				$(addprefix $(CON_PATH),Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp FForm.cpp)\
				
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
