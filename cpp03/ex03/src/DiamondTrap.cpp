/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:49:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
    this->ClapTrap::m_name += "_clap_name";
	this->m_name = "Default";
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string str)
{
    this->m_name = str;
    this->ClapTrap::m_name = str + "_clap_name";
    FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& d) : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = d;
    this->ClapTrap::m_name = this->m_name + "_clap_name";
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap&d)
{
    std::cout << "DiamondTrap copy assignement operator called" << std::endl;
	if (this == &d)
		return *this;
	this->m_hitPoint = d.m_hitPoint;
	this->m_name = d.m_name;
	this->m_energyPoint = d.m_energyPoint;
	this->m_attackDamage = d.m_attackDamage;
	return *this;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name is both " << this->m_name << " and " << this->ClapTrap::m_name << std::endl; // both name and ClapTrap::name are called
}
