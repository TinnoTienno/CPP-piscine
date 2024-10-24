/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 17:03:23 by eschussl         ###   ########.fr       */
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
	integer = val << fract;
}

Fixed::Fixed( const float val )
{
	std::cout << "Float constructor called" << std::endl;
	integer = (int)(roundf(val * ( 1 << fract)));
}
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (integer);
}

Fixed::Fixed (const Fixed &t)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = t;
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	integer = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &f)
		return (*this);
	integer = f.getRawBits();
	return (*this);
}

float	Fixed::toFloat ( void ) const
{
	return (float(integer) / float(1 << fract));
}

std::ostream&	operator<<( std::ostream& os, const Fixed &F)
{
	os << F.toFloat();
	return (os);
}

int		Fixed::toInt ( void ) const
{
	return (integer >> fract);
}