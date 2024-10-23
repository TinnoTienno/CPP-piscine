/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:05:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/22 16:50:26 by eschussl         ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed&);
	Fixed(const int);
	Fixed(const float);
	~Fixed();
	
	float	toFloat (void) const;
	int		toInt (void) const;
	int		getRawBits(void) const;
	
	void	setRawBits(int const raw);
	Fixed&	operator=(const Fixed&);
};

std::ostream&	operator<<( std::ostream&, const Fixed &);

#endif