/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:05:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:04:25 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int					m_integer;
		static const int	m_fract = 8;
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		
		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
		
		void	setRawBits(int const);
		Fixed&	operator=(const Fixed&);
}	;

std::ostream&	operator<<( std::ostream&, const Fixed&);

#endif