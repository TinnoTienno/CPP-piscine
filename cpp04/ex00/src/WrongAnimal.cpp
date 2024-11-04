/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:06:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 13:40:51 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	this->type = "Weird Blob";
	std::cout << "Default Wronganimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	*this = a;
	std::cout << "Copy Wronganimal constructor called" << std::endl;	
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
	std::cout << "WrongAnimal copy assignement operator called" << std::endl;
	if (this == &a)
		return (*this);
	type = a.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << type << " doesnt know what to do !" <<std::endl;
}