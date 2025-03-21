/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:16:47 by eschussl         ###   ########.fr       */
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
	this->setRawBits((int)(roundf(f * ( 1 << this->m_fract))));
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
	// std::cout << "getRawBits member function called" << std::endl;
	return this->m_integer;
}

void	Fixed::setRawBits(int const i)
{
	// std::cout << "setRawBits called" << std::endl;
	this->m_integer = i;
}

float	Fixed::toFloat() const
{
	return float(this->getRawBits()) / (float)(1 << this->m_fract);
}

int		Fixed::toInt() const
{
	return this->getRawBits() >> this->m_fract;
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return !(this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>(const Fixed &obj) const
{
	return this->getRawBits() > obj.getRawBits();
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return !(this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return this->getRawBits() == obj.getRawBits();
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return !(this->getRawBits() == obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &obj)
{
	return this->toFloat() + obj.toFloat(); // we cant directly return a float considring we got a float constructor which gonna output a Fixed object
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	return this->toFloat() - obj.toFloat(); // same here and after
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	return this->toFloat() * obj.toFloat();
}

Fixed	Fixed::operator/(const Fixed &obj) // because we cant bitshift float values in c++, we need to scale before the division to maintain precision
{
	return this->toFloat() / obj.toFloat();
}

Fixed&	Fixed::operator++() // pre incrementation
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int) // post incrementation
{
	Fixed Old = *this;
	this->operator++();
	return Old;
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed Old = *this;
	this->operator--();
	return Old;
}

const Fixed&	Fixed::min(const Fixed &F1, const Fixed &F2)
{
	return F1 <= F2 ? F1: F2;
}

const Fixed&	Fixed::max(const Fixed &F1, const Fixed &F2)
{
	return F1 >= F2 ? F2: F1;
}

Fixed&	Fixed::min(Fixed &F1, Fixed &F2)
{
	return F1 <= F2 ? F1: F2;
}

Fixed&	Fixed::max(Fixed &F1, Fixed &F2)
{
	return F1 >= F2 ? F2: F1;
}
std::ostream&	operator<<(std::ostream& os,const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}
