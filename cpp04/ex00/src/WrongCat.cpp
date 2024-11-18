/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:35 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:54:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal()
{
	*this = c;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;	
}

WrongCat& WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat copy assignement operator called" << std::endl;
	if (this == &c)
		return *this;
	type = c.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << type << " starts growling..." << std::endl;
	std::cout << "MeoooOOOOOOOWWWW !" << std::endl;
}
