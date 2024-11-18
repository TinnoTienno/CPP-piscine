/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:28:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:03:07 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					m_integer;
		static const int	m_fract = 8; //value is set there so it cant be changed
	public:
		Fixed();
		Fixed(Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const);
};

#endif