/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:30:15 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:56:44 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
	Weapon club = Weapon("crude spiked club"); // test copie
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	HumanB jim("Jim");
	Weapon sword("rusty looking sword");
	jim.setWeapon(sword);
	jim.attack();
	jim.setWeapon(NULL);
	jim.attack();
	return 0;
}