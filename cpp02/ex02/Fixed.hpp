/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:05:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/19 17:19:02 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int					integer;
	static const int	fract = 8;
public:
	Fixed	();
	Fixed	( const Fixed& );
	Fixed	( const int );
	Fixed	( const float );
	~Fixed	();
	
	float	toFloat ( void ) const;
	int		toInt ( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	
	bool	operator<( const Fixed& ) const;
	bool	operator>( const Fixed& ) const;
	bool	operator<=( const Fixed& ) const;
	bool	operator>=( const Fixed& ) const;
	bool	operator==( const Fixed& ) const;
	bool	operator!=( const Fixed& ) const;
	
	Fixed&	operator=( const Fixed& );
	Fixed&	operator+( const Fixed& );
	Fixed&	operator-( const Fixed& );
	Fixed&	operator*( const Fixed& );
	Fixed&	operator/( const Fixed& );

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	
	static	Fixed&	min( Fixed&, Fixed & );
	static	const Fixed&	min( const Fixed&, const Fixed & ); 
	static	Fixed&	max( Fixed&, Fixed & );
	static	const Fixed&	max( const Fixed&, const Fixed & ); 
};

std::ostream&	operator<<( std::ostream&, const Fixed &);

#endif