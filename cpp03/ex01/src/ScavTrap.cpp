/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 13:57:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    ClapTrap::hitPoint = 100;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
    
}