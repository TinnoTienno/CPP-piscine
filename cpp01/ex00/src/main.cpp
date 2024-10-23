/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:30:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/26 12:31:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name);

int	main (int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return 1;
	randomChump(argv[1]);
	if (argc == 2)
		return (0);
	Zombie *Zombie2 = newZombie(argv[2]);
	Zombie2->announce();
	delete (Zombie2);
}