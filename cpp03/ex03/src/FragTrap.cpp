/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:26:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 14:37:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    setAD();
	setEP();
	setHP();
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string str) : ClapTrap()
{
    name = str;
    setAD();
	setEP();
	setHP();
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

void FragTrap::setHP(void)	{hitPoint = 100;}
void FragTrap::setEP(void)	{energyPoint = 100;}
void FragTrap::setAD(void)	{attackDamage = 30;}