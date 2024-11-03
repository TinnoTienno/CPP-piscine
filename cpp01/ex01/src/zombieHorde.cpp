/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:09:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 15:10:35 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "Not enough zombies to create" << std::endl;
		return NULL;
	}
	Zombie *The_Horde = new Zombie[N]; // uses the new[] here so we need a delete[] in main
	int i = 0;
	while (i < N)
	{
		The_Horde[i].set(name); // initialize the objects by setting their name
		i++;
	}
	return (The_Horde); // returns the pointer to first Zombie
}