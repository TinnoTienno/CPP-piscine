/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:15:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:17:06 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a(3);
	Fixed const b( Fixed( 5.8f ) / Fixed( 2 ) );
	std::cout << "b = " << b  << std::endl;
	
	Fixed c = a - b;
	// std ::cout <<  << std::endl;
	std::cout << a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	
	std::cout << "min " << c.min(a, b) << std::endl; // this is a test, but it works holy shit
	std::cout << "c " << c << std::endl;
	std::cout << "min " << Fixed::min(a, c) << std::endl;

	return 0;
}