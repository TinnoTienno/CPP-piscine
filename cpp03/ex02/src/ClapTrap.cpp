/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:18:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 17:33:56 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = c;
}
ClapTrap::ClapTrap(std::string str)
{
	_name = str;
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
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
	_hitPoint = c._hitPoint;
	_name = c._name;
	_energyPoint = c._energyPoint;
	_attackDamage = c._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_energyPoint)
	{
		std::cout << "ClapTrap " << _name << " tried to attack " << target << " but it has no more energy point." << std::endl;
		return;
	}
	if (!_hitPoint)
	{
		std::cout << "ClapTrap " << _name << " tried to attack but it is already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !" << std::endl;
	_energyPoint--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoint)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	_hitPoint -= amount;
	std::cout << "ClapTrap " << _name << " got hit for " << amount << " damages." << std::endl;
	if (_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " died." << std::endl;
		_hitPoint = 0;
	}
	else
		std::cout << "ClapTrap " << _name << " is left with " << _hitPoint << " hit points." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoint)
	{
		std::cout << "ClapTrap " << _name << " tried to repair itself but it has no more energy point." << std::endl;
		return;
	}
	if (!_hitPoint)
	{
		std::cout << "ClapTrap " << _name << " tried to repair itself but it is already dead." << std::endl;
		return;
	}
	_hitPoint += amount;
	std::cout << "ClapTrap " << _name << " repairs himself for " << amount << " hit points. He now has " << _hitPoint << " hit points." << std::endl;
}




