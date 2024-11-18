/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:22:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:50:07 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string str, Weapon& new_weap) : m_name(str), m_weapon(new_weap) { };

void	HumanA::attack( void )
{
	std::cout << this->m_name << " attacks with their " << m_weapon.getType() << std::endl;
}

