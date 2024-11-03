/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:30:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 14:59:10 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main (int argc, char **argv) // needs 3 arguments to display the full test
{
	if (argc == 1 || argc > 4)
		return 1;
	Zombie zombie(argv[1]); // last zombie to be destroyed
	zombie.announce();
	if (argc == 2)
		return (0);
	randomChump(argv[2]);
	if (argc == 3)
		return (0);
	Zombie *Zombie2 = newZombie(argv[3]);
	Zombie2->announce();
	delete (Zombie2); // delete is mandatory considering we use new in newZombie()
}