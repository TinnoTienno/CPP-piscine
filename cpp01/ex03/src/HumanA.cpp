/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:22:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:20:45 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string str, Weapon& new_weap) : _name(str), _weapon(new_weap) { };

void	HumanA::attack( void )
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

