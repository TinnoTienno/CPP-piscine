# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:05:09 by eschussl          #+#    #+#              #
#    Updated: 2024/10/24 18:25:55 by eschussl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	DiamondTrap

CC 			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g -Wshadow -Wno-shadow
SRCS		=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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
