/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:18:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 15:29:28 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = c;
}
ClapTrap::ClapTrap(std::string str)
{
	name = str;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& c)
{
    std::cout << "ClapTrap copy assignement operator called" << std::endl;
	if (this == &c)
		return (*this);
	hitPoint = c.hitPoint;
	name = c.name;
	energyPoint = c.energyPoint;
	attackDamage = c.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!energyPoint)
	{
		std::cout << "ClapTrap " << name << " tried to attack " << target << " but it has no more energy point." << std::endl;
		return;
	}
	if (!hitPoint)
	{
		std::cout << "ClapTrap " << name << " tried to attack but it is already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
	energyPoint--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoint)
	{
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return ;
	}
	hitPoint -= amount;
	std::cout << "ClapTrap " << name << " got hit for " << amount << " damages." << std::endl;
	if (hitPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " died." << std::endl;
		hitPoint = 0;
	}
	else
		std::cout << "ClapTrap " << name << " is left with " << hitPoint << " hit points." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoint)
	{
		std::cout << "ClapTrap " << name << " tried to repair itself but it has no more energy point." << std::endl;
		return;
	}
	if (!hitPoint)
	{
		std::cout << "ClapTrap " << name << " tried to repair itself but it is already dead." << std::endl;
		return;
	}
	hitPoint += amount;
	std::cout << "ClapTrap " << name << " repairs himself for " << amount << " hit points. He now has " << hitPoint << " hit points." << std::endl;
}




