/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:26:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 18:35:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string str) : ClapTrap()
{
    hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
    name = str;
	std::cout << "FragTrap string constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &f) : ClapTrap()
{
    *this = f;
	std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &f)
{
    std::cout << "FragTrap copy assignement operator called" << std::endl;
	if (this == &f)
		return (*this);
	hitPoint = f.hitPoint;
	name = f.name;
	energyPoint = f.energyPoint;
	attackDamage = f.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " is requesting a high five." << std::endl;
}