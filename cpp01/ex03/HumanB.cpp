/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 13:55:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &new_weap)
{
	weapon = &new_weap;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	
}