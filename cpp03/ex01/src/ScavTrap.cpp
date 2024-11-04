/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 13:11:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() //this is where ScavTrap constructors will inherit the ClapTrap Constructors
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    ClapTrap::_hitPoint = 100;
    ClapTrap::_energyPoint = 50;
    ClapTrap::_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = s;
}
ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap ScavTrap::operator=(const ScavTrap &s)
{
    std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this == &s)
		return (*this);
	_hitPoint = s._hitPoint;
	_name = s._name;
	_energyPoint = s._energyPoint;
	_attackDamage = s._attackDamage;
	return (*this);
}

void ScavTrap::guardGate(void)
{
    if (!_energyPoint)
	{
		std::cout << "ScavTrap " << _name << " tried to guard but it has no more energy point." << std::endl;
		return;
	}
	if (!_hitPoint)
	{
		std::cout << "ScavTrap " << _name << " tried to guard but it is already dead." << std::endl;
		return;
	}
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
    --_energyPoint;
}

void ScavTrap::attack(const std::string& target) // redefinition of attack
{
    if (!_energyPoint)
	{
		std::cout << "ScavTrap " << _name << " tried to attack " << target << " but it has no more energy point." << std::endl;
		return;
	}
	if (!_hitPoint)
	{
		std::cout << "ScavTrap " << _name << " tried to attack but it is already dead." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !" << std::endl;
	_energyPoint--;
}