/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:05:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/10 17:51:52 by eschussl         ###   ########.fr       */
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
	
	std::ostream&	operator<< ( std::ostream&);
	
	bool	operator<( const Fixed& );
	bool	operator>( const Fixed& );
	bool	operator<=( const Fixed& );
	bool	operator>=( const Fixed& );
	bool	operator==( const Fixed& );
	bool	operator!=( const Fixed& );
	
	Fixed&	operator=( const Fixed& );
	Fixed&	operator+( const Fixed& );
	Fixed&	operator-( const Fixed& );
	Fixed&	operator*( const Fixed& );
	Fixed&	operator/( const Fixed& );

	Fixed&	operator++();
	Fixed&	operator++(int);
	Fixed&	operator--();
	Fixed&	operator--(int);
	
	static	Fixed&	min( Fixed&, Fixed & );
	static	Fixed&	min( const Fixed&, const Fixed & ); 
	static	Fixed&	max( Fixed&, Fixed & );
	static	Fixed&	max( const Fixed&, const Fixed & ); 
};

#endif