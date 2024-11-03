/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:26:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 17:34:32 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string str) : ClapTrap()
{
    _hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
    _name = str;
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
	_hitPoint = f._hitPoint;
	_name = f._name;
	_energyPoint = f._energyPoint;
	_attackDamage = f._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    
    std::cout << "FragTrap " << _name << " is requesting a high five." << std::endl;
}