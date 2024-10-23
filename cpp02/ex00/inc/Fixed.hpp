/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:28:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/10 14:49:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					integer;
	static const int	fract = 8;
public:
	Fixed();
	Fixed( Fixed& );
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	Fixed& operator=( const Fixed& );
};

#endif