/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:50:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include <string>

HumanB::HumanB(std::string str) : m_weapon(NULL), m_name(str) { }

void	HumanB::setWeapon(Weapon *new_weap) { this->m_weapon = new_weap; }

void	HumanB::setWeapon(Weapon &new_weap) { this->m_weapon = &new_weap; }

void	HumanB::attack()
{
	if (this->m_weapon)
		std::cout << this->m_name << " attacks with their " << m_weapon->getType() << std::endl;
	else
		std::cout << this->m_name << " doesnt have a weapon, so he runs away. CHICKEEEEEEN !" << std::endl;
}