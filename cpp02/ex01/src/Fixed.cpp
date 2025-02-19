/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:06:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Fixed default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int i)
{
	std::cout << "Fixed int constructor called" << std::endl;
	this->setRawBits(i << this->m_fract);
}

Fixed::Fixed(const float f)
{
	std::cout << "Fixed float constructor called" << std::endl;
	this->setRawBits((roundf(f * ( 1 << this->m_fract))));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	this->setRawBits(obj.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return this->m_integer;
}

void	Fixed::setRawBits(int const i)
{
	// std::cout << "setRawBits called" << std::endl;
	this->m_integer = i;
}

int		Fixed::toInt() const
{
	return (this->getRawBits() >> this->m_fract);
}

float	Fixed::toFloat() const
{
	return (float(this->getRawBits()) / (1 << this->m_fract));
}

std::ostream&	operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}
