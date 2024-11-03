/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:28:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:23:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_integer;
		static const int	_fract = 8;
	public:
		Fixed();
		Fixed(Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const);
};

#endif