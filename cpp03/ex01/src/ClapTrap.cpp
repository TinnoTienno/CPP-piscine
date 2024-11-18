/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:18:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:35:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	this->m_name = "Default";
	this->m_hitPoint = 10;
	this->m_energyPoint = 10;
	this->m_attackDamage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}
ClapTrap::ClapTrap(std::string str)
{
	this->m_name = str;
	this->m_hitPoint = 10;
	this->m_energyPoint = 10;
	this->m_attackDamage = 0;
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &obj)
{
    std::cout << "ClapTrap copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	this->m_hitPoint = obj.m_hitPoint;
	this->m_name = obj.m_name;
	this->m_energyPoint = obj.m_energyPoint;
	this->m_attackDamage = obj.m_attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->m_energyPoint)
	{
		std::cout << "ClapTrap " << this->m_name << " tried to attack " << target << " but it has no more energy point." << std::endl;
		return;
	}
	if (!this->m_hitPoint)
	{
		std::cout << "ClapTrap " << this->m_name << " tried to attack but it is already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage !" << std::endl;
	this->m_energyPoint--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->m_hitPoint)
	{
		std::cout << "ClapTrap " << this->m_name << " is already dead." << std::endl;
		return ;
	}
	this->m_hitPoint -= amount;
	std::cout << "ClapTrap " << this->m_name << " got hit for " << amount << " damages." << std::endl;
	if (this->m_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " died." << std::endl;
		this->m_hitPoint = 0;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " is left with " << this->m_hitPoint << " hit points." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->m_energyPoint)
	{
		std::cout << "ClapTrap " << this->m_name << " tried to repair itself but it has no more energy point." << std::endl;
		return;
	}
	if (!this->m_hitPoint)
	{
		std::cout << "ClapTrap " << this->m_name << " tried to repair itself but it is already dead." << std::endl;
		return;
	}
	this->m_hitPoint += amount;
	std::cout << "ClapTrap " << this->m_name << " repairs himself for " << amount << " hit points. He now has " << this->m_hitPoint << " hit points." << std::endl;
}




