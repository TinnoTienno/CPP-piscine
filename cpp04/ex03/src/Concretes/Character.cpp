/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Charater.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:00:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 17:03:18 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}
Character::Character(const Character&)
{
	std::cout << "Character copy constructor called" << std::endl;
	
}
Character& Character::operator=(const Character&)
{
	std::cout << "Character copy assignement operator called" << std::endl;

}
Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;

}

Character& Character::Clone()
{
	
}