/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:26:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:50:38 by eschussl         ###   ########.fr       */
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
    this->m_name = str;
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
	this->m_hitPoint = f.m_hitPoint;
	this->m_name = f.m_name;
	this->m_energyPoint = f.m_energyPoint;
	this->m_attackDamage = f.m_attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->m_name << " is requesting a high five." << std::endl;
}

void FragTrap::setHP(void)	{this->m_hitPoint = 100;}
void FragTrap::setEP(void)	{this->m_energyPoint = 100;}
void FragTrap::setAD(void)	{this->m_attackDamage = 30;}