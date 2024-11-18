/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:43:20 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = s;
}
ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
    this->m_hitPoint = 100;
    this->m_energyPoint = 50;
    this->m_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap ScavTrap::operator=(const ScavTrap& s)
{
    std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this == &s)
		return (*this);
	this->m_hitPoint = s.m_hitPoint;
	this->m_name = s.m_name;
	this->m_energyPoint = s.m_energyPoint;
	this->m_attackDamage = s.m_attackDamage;
	return (*this);
}

void ScavTrap::guardGate(void)
{
    if (!this->m_energyPoint)
	{
		std::cout << "ScavTrap " << this->m_name << " tried to guard but it has no more energy point." << std::endl;
		return;
	}
	if (!this->m_hitPoint)
	{
		std::cout << "ScavTrap " << this->m_name << " tried to guard but it is already dead." << std::endl;
		return;
	}
    std::cout << "ScavTrap " << this->m_name << " is now in Gate keeper mode." << std::endl;
    --this->m_energyPoint;
}

void ScavTrap::attack(const std::string& target)
{
    if (!this->m_energyPoint)
	{
		std::cout << "ScavTrap " << this->m_name << " tried to attack " << target << " but it has no more energy point." << std::endl;
		return;
	}
	if (!this->m_hitPoint)
	{
		std::cout << "ScavTrap " << this->m_name << " tried to attack but it is already dead." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage !" << std::endl;
	this->m_energyPoint--;
}