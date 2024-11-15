/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:37:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 16:35:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &c) : Animal()
{
	*this = c;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;	
}

Dog& Dog::operator=(const Dog &d)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this == &d)
		return (*this);
	type = d.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << type << " starts barking..." << std::endl;
	std::cout << "Uuuu Waaaf ! Wwwaaff !" << std::endl;
}