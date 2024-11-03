/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:33:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 15:11:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>
#include <iostream>

Zombie*	zombieHorde(int N, std::string name);

int	main(int argc, char **argv) // first arg is the horde size, second the name
{
	if (argc != 3)
		return (1);
	Zombie *The_Horde = zombieHorde(atoi(argv[1]), argv[2]);
	int i = 0;
	while (i < atoi(argv[1]))
	{
		std::cout << "Zombie "<< i << ": "; // just to be sure of how many zombies are actually returned
		The_Horde[i++].announce();
	}
	delete[](The_Horde); // uses the delete[] here
}