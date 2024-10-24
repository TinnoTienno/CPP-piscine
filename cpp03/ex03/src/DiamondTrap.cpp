/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 18:34:36 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
    ClapTrap::name = "_clap_name";
    hitPoint = FragTrap::hitPoint;
	energyPoint = ScavTrap::energyPoint;
	attackDamage = FragTrap::attackDamage;
    std::cout << attackDamage << " Fragtrap : " << FragTrap::attackDamage << std::endl;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string str)
{
    name = str;
    ClapTrap::name = str + "_clap_name";
    hitPoint = FragTrap::hitPoint;
	energyPoint = ScavTrap::energyPoint;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& d) : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = d;
    ClapTrap::name = name + "_clap_name";
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap&d)
{
    std::cout << "DiamondTrap copy assignement operator called" << std::endl;
	if (this == &d)
		return (*this);
	hitPoint = d.hitPoint;
	name = d.name;
	energyPoint = d.energyPoint;
	attackDamage = d.attackDamage;
	return (*this);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name is both " << name << " and " << ClapTrap::name << std::endl;
}

void    DiamondTrap::attack(const std::string target)
{
    ScavTrap::attack(target);
}