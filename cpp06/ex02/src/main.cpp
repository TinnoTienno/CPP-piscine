/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 16:03:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>

Base *generate()
{
	srand((unsigned) time (NULL));
	int random = rand();

	if (!(random % 3))
	{
		std::cout << "A" << std::endl;
		return (new A);
	}
	if (random % 3 == 1)
	{
		std::cout << "B" << std::endl;
		return (new B);
	}
	std::cout << "C" << std::endl;
	return (new C);
}

// void identify(Base *p)
// {
// 	try
// 	{
		
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// }

// void identify(Base& p)
// {
	
// }
int main()
{
	Base *ptr;
	// ptr = generate();
	(void) ptr;
	// identify(ptr);
	// identify(*ptr);
}