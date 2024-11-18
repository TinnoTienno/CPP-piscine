/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:52:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 13:09:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria()
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = obj;
}

Ice& Ice::operator=(const Ice &obj)
{
	// std::cout << "Ice copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}


void    Ice::use(ICharacter&target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria* Ice::clone() const { return new Ice(*this); }