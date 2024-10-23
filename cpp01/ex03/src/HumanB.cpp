/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/21 18:15:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon *new_weap)
{
	weapon = new_weap;
}

void	HumanB::setWeapon(Weapon &new_weap)
{
	weapon = &new_weap;
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " doesnt have a weapon, so he runs away. CHICKEEEEEEN !" << std::endl;
}