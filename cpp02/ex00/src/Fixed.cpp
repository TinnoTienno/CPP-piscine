/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:30:18 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 16:52:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Fixed default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(Fixed &obj)
{
	std::cout << "Fixed copy constructor called" << std::endl;
	this->setRawBits(obj.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->setRawBits(obj.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

int	Fixed::getRawBits() const // fyi, getRawBits() = getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_integer);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_integer = raw;
}