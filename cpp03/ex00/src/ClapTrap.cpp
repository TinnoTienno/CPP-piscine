/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:18:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/23 17:38:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string str)
{
	name = str;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	std::cout << "Constructor called" << std::endl;
}
void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoint -= amount;
	std::cout << "ClapTrap " << name << " got hit for " << amount << " damages." << std::endl;
	if (hitPoint <= 0)
		std::cout << "ClapTrap " << name << " died." << std::endl;
	else
		std::cout << "ClapTrap " << name << "is left with " << hitPoint << " hit points." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	hitPoint += amount;
	std::cout << "ClapTrap " << name << " repairs himself for " << amount << " hit points. He now has " << hitPoint << " hit points." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}
