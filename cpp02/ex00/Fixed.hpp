/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:28:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/09 18:32:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					integer;
	static const int	fract;
public:
	Fixed(/* args */);
	~Fixed();
	int	getRawBits( void ) const;
	void	setRawBits( int const raw);
};



#endif