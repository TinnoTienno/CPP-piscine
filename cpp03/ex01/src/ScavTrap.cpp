/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 15:33:25 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    ClapTrap::hitPoint = 100;
    ClapTrap::energyPoint = 50;
    ClapTrap::attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = s;
}
ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap ScavTrap::operator= (const ScavTrap& s)
{
    std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this == &s)
		return (*this);
	hitPoint = s.hitPoint;
	name = s.name;
	energyPoint = s.energyPoint;
	attackDamage = s.attackDamage;
	return (*this);
}
void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;    
}