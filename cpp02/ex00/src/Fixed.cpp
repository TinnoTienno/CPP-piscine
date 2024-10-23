/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:30:18 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/10 15:03:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	integer = 0;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (0);
}

Fixed::Fixed (Fixed& t)
{
	std::cout << "Copy constructor called" << std::endl;
	integer = t.getRawBits();
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRaBitsw called" << std::endl;
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