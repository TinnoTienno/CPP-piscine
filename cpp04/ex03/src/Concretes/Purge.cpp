/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Purge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:10:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 15:05:00 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Purge.hpp"

Purge::Purge()
{
	type = "purge";
	// std::cout << "Purge default constructor called" << std::endl;
}

Purge::Purge(const Purge &obj) : AMateria()
{
	// std::cout << "Purge copy constructor called" << std::endl;
	*this = obj;
}

Purge& Purge::operator=(const Purge &obj)
{
	// std::cout << "Purge copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}

Purge::~Purge()
{
	std::cout << "Purge destructor called" << std::endl;
}


void    Purge::use(ICharacter&target)
{
	std::cout << "* shoots an Purge bolt at " << target.getName() << std::endl;
}

AMateria* Purge::clone() const
{
	Purge *res;

	res = new(Purge);
	res->type = this->type;
	return (res);
}