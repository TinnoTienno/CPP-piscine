/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:55:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	// std::cout << "Fixed default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int i)
{
	// std::cout << "Fixed int constructor called" << std::endl;
	this->setRawBits(i << _fract);
}

Fixed::Fixed(const float f)
{
	// std::cout << "Fixed float constructor called" << std::endl;
	this->setRawBits((int)(roundf(f * ( 1 << _fract))));
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Fixed copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->setRawBits(obj.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Fixed destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_integer);
}

void	Fixed::setRawBits(int const i)
{
	// std::cout << "setRawBits called" << std::endl;
	_integer = i;
}

float	Fixed::toFloat() const
{
	return (float(this->getRawBits()) / (float)(1 << _fract));
}

int		Fixed::toInt() const
{
	return (this->getRawBits() >> _fract);
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
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return !(this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return !(this->getRawBits() == obj.getRawBits());
}

Fixed&	Fixed::operator+(const Fixed &obj)
{
	this->setRawBits(this->getRawBits() + obj.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed &obj)
{
	this->setRawBits(this->getRawBits() - obj.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed &obj)
{
	this->setRawBits((this->getRawBits() * obj.getRawBits()) >> _fract);
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed &obj) // I think this one is broken
{
	this->setRawBits(this->getRawBits() / obj.getRawBits() << _fract);
	return (*this);
}

Fixed&	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed Old = *this;
	operator++();
	return (Old);
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed Old = *this;
	operator--();
	return (Old);
}

const Fixed&	Fixed::min(const Fixed &F1,const Fixed &F2)
{
	return (F1 <= F2 ? F2: F1);
}

const Fixed&	Fixed::max(const Fixed &F1,const Fixed &F2)
{
	return (F1 >= F2 ? F1: F2);
}

std::ostream&	operator<<(std::ostream& os,const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}