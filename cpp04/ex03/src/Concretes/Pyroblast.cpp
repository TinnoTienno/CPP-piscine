/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pyroblast.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:52:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 15:03:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pyroblast.hpp"

Pyroblast::Pyroblast()
{
	type = "pyroblast";
	// std::cout << "Pyroblast default constructor called" << std::endl;
}

Pyroblast::Pyroblast(const Pyroblast &obj) : AMateria()
{
	// std::cout << "Pyroblast copy constructor called" << std::endl;
	*this = obj;
}

Pyroblast& Pyroblast::operator=(const Pyroblast &obj)
{
	// std::cout << "Pyroblast copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

Pyroblast::~Pyroblast()
{
	std::cout << "Pyroblast destructor called" << std::endl;
}


void    Pyroblast::use(ICharacter&target)
{
	std::cout << "* shoots an Pyroblast at " << target.getName() << std::endl;
}

AMateria* Pyroblast::clone() const
{
	Pyroblast *res;

	res = new(Pyroblast);
	res->type = this->type;
	return (res);
}