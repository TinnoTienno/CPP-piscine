/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/23 14:38:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	integer = 0;
}

Fixed::Fixed( const int val )
{
	std::cout << "Int constructor called" << std::endl;
	int res = val << fract;
	integer = res;
}

Fixed::Fixed( const float val )
{
	std::cout << "Float constructor called" << std::endl;
	int res = (int)(roundf(val * ( 1 << fract)));
	integer = res;
}

Fixed::Fixed (const Fixed &t)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = t;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (integer);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	integer = raw;
}

float	Fixed::toFloat ( void ) const
{
	return (float(integer) / (float)(1 << fract));
}

int		Fixed::toInt ( void ) const
{
	return (integer >> fract);
}

bool	Fixed::operator<( const Fixed& f2) const
{
	return (integer < f2.integer);
}

bool	Fixed::operator>=( const Fixed& f2) const
{
	return !(integer < f2.integer);
}

bool	Fixed::operator>( const Fixed& f2) const
{
	return (integer > f2.integer);
}

bool	Fixed::operator<=( const Fixed& f2) const
{
	return !(integer > f2.integer);
}

bool	Fixed::operator==( const Fixed& f2) const
{
	return (integer == f2.integer);
}

bool	Fixed::operator!=( const Fixed& f2) const
{
	return !(integer == f2.integer);
}

Fixed& Fixed::operator=( const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &f)
		return (*this);
	integer = f.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator+( const Fixed& f2 )
{
	integer += f2.integer;
	return (*this);
}

Fixed&	Fixed::operator-( const Fixed& f2 )
{
	integer -= f2.integer;
	return (*this);
}

Fixed&	Fixed::operator*( const Fixed& f2 )
{
	integer *= f2.integer;
	integer >>= f2.fract;
	return (*this);
}

Fixed&	Fixed::operator/( const Fixed& f2 )
{
	integer /= f2.integer;
	return (*this);
}

Fixed&	Fixed::operator++()
{
	integer += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed Old = *this;
	operator++();
	return (Old);
}

Fixed&	Fixed::operator--()
{
	integer -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed Old = *this;
	operator--();
	return (Old);
}

std::ostream&	operator<<( std::ostream& os, const Fixed &F)
{
	os << F.toFloat();
	return (os);
}

Fixed&	Fixed::min( Fixed& F1, Fixed &F2 )
{
	return (F1 <= F2 ? F1 : F2);
}
const Fixed&	Fixed::min( const Fixed& F1, const Fixed &F2 )
{
	return (F1 <= F2 ? F2: F1);
}
Fixed&	Fixed::max( Fixed& F1, Fixed &F2 )
{
	return (F1 >= F2 ? F1: F2);
}
const Fixed&	Fixed::max( const Fixed& F1, const Fixed &F2 )
{
	return (F1 >= F2 ? F1: F2);
}