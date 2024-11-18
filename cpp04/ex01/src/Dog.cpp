/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:37:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:57:58 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	this->brain = new(Brain);
	std::cout << "Default dog constructor called" << std::endl;
}

Dog::Dog(const Dog &c) : Animal()
{
	this->brain = NULL;
	*this = c;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete (brain);
	std::cout << "Dog destructor called" << std::endl;	
}

Dog& Dog::operator=(const Dog &d)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this == &d)
		return *this;
	type = d.type;
	if (this->brain)
		delete (this->brain);
	this->brain = new(Brain);
	*brain = *d.brain;

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << type << " starts barking..." << std::endl;
	std::cout << "Uuuu Waaaf ! Wwwaaff !" << std::endl;
}

std::string	Dog::getIdea(const int index) const { return (brain->getIdea(index)); }

void	Dog::setIdea(const int index, const std::string str) { brain->setIdea(index, str); }