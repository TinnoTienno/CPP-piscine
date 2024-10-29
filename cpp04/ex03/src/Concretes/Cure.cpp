/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:10:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/29 15:14:54 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria()
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = obj;
}

Cure& Cure::operator=(const Cure &obj)
{
	std::cout << "Cure copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}


void    Cure::use(ICharacter&target)
{
	std::cout << "* shoots an Cure bolt at " << target.getName() << std::endl;
}

AMateria* Cure::clone() const
{
	Cure *res;

	res = new(Cure);
	res->type = this->type;
	return (res);
}