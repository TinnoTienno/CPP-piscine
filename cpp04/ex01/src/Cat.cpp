/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:35 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 14:31:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	this->brain = new(Brain);
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal()
{
	this->brain = NULL;
	*this = c;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete(brain);
	std::cout << "Cat destructor called" << std::endl;	
}

Cat& Cat::operator=(const Cat &c)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this == &c)
		return (*this);
	type = c.type;
	if (this->brain)
		delete this->brain;
	this->brain = new(Brain);
	*brain = *c.brain;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << type << " starts growling..." << std::endl;
	std::cout << "MeoooOOOOOOOWWWW !" << std::endl;
}

std::string	Cat::getIdea(const int index) const
{
	return (brain->getIdea(index));
}

void	Cat::setIdea(const int index, const std::string str)
{
	brain->setIdea(index, str);
}