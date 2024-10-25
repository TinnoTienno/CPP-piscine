/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 14:38:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    setAD();
	setEP();
	setHP();
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = s;
}
ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	setAD();
	setEP();
	setHP();
    std::cout << "ScavTrap string constructor called" << std::endl;
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
    if (!energyPoint)
	{
		std::cout << "ScavTrap " << name << " tried to guard but it has no more energy point." << std::endl;
		return;
	}
	if (!hitPoint)
	{
		std::cout << "ScavTrap " << name << " tried to guard but it is already dead." << std::endl;
		return;
	}
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
    --energyPoint;
}

void ScavTrap::attack(const std::string& target)
{
    if (!energyPoint)
	{
		std::cout << "ScavTrap " << name << " tried to attack " << target << " but it has no more energy point." << std::endl;
		return;
	}
	if (!hitPoint)
	{
		std::cout << "ScavTrap " << name << " tried to attack but it is already dead." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
	energyPoint--;
}

void ScavTrap::setHP(void)	{hitPoint = 100;}
void ScavTrap::setEP(void)	{energyPoint = 50;}
void ScavTrap::setAD(void)	{attackDamage = 20;}