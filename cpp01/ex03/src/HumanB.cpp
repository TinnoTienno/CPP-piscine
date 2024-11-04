/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 15:29:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include <string>

HumanB::HumanB(std::string str) : _weapon(NULL), _name(str) { }

void	HumanB::setWeapon(Weapon *new_weap) { _weapon = new_weap; }

void	HumanB::setWeapon(Weapon &new_weap) { _weapon = &new_weap; }

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesnt have a weapon, so he runs away. CHICKEEEEEEN !" << std::endl;
}