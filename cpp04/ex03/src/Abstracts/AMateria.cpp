/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:25:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 14:41:57 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	next = NULL;
	std::cout << "AMaterial default constructor called" << std::endl;
}
AMateria::AMateria(std::string const &type)
{
	next = NULL;
	std::cout << "AMaterial string constructor called" << std::endl;
	this->type = type;
}
AMateria::AMateria(const AMateria &obj)
{
	next = NULL;
	std::cout << "AMaterial copy constructor called" << std::endl;
	*this = obj;
}
AMateria& AMateria::operator=(const AMateria &obj)
{
	std::cout << "AMaterial copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	type = obj.type;
	return (*this);
}
AMateria::~AMateria()
{
	std::cout << "AMaterial destructor called" << std::endl;
}
   
const std::string& AMateria::getType() const //Returns the materia type
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia undefined, I cant use it on " << target.getName() << std::endl;
}
