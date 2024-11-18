/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:52:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 13:08:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fireball.hpp"

Fireball::Fireball()
{
	type = "fireball";
	// std::cout << "Fireball default constructor called" << std::endl;
}

Fireball::Fireball(const Fireball &obj) : AMateria()
{
	// std::cout << "Fireball copy constructor called" << std::endl;
	*this = obj;
}

Fireball& Fireball::operator=(const Fireball &obj)
{
	// std::cout << "Fireball copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}

Fireball::~Fireball()
{
	std::cout << "Fireball destructor called" << std::endl;
}


void    Fireball::use(ICharacter&target)
{
	std::cout << "* shoots an Fireball at " << target.getName() << std::endl;
}

AMateria* Fireball::clone() const { return new Fireball(*this); }