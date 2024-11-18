/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:06:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:58:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	this->type = "Weird Blob";
	std::cout << "Default animal constructor called" << std::endl;
}
Animal::Animal(const Animal &a)
{
	*this = a;
	std::cout << "Copy animal constructor called" << std::endl;	
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
Animal& Animal::operator=(const Animal &a)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this == &a)
		return *this;
	type = a.type;
	return *this;
}
std::string	Animal::getType(void) const { return type; }

void	Animal::makeSound(void) const 
{
	std::cout << type << " doesnt know what to do !" <<std::endl;
}