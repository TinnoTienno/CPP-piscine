/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:05:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:54:56 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int					_integer;
	static const int	_fract = 8;
public:
	Fixed	();
	Fixed	(const int);
	Fixed	(const float);
	Fixed	(const Fixed&);
	Fixed&	operator=(const Fixed&);
	~Fixed	();
	
	float	toFloat() const;
	int		toInt() const;
	int		getRawBits() const;
	void	setRawBits(int const);
	
	bool	operator<(const Fixed&) const;
	bool	operator>(const Fixed&) const;
	bool	operator<=(const Fixed&) const;
	bool	operator>=(const Fixed&) const;
	bool	operator==(const Fixed&) const;
	bool	operator!=(const Fixed&) const;
	
	Fixed&	operator+(const Fixed&);
	Fixed&	operator-(const Fixed&);
	Fixed&	operator*(const Fixed&);
	Fixed&	operator/(const Fixed&);

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	
	static	const Fixed&	min(const Fixed&, const Fixed&); 
	static	const Fixed&	max(const Fixed&, const Fixed&); 
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif