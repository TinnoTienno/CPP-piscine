/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 16:25:08 by eschussl         ###   ########.fr       */
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

void identify(Base *p)
{
		A *resa = dynamic_cast<A*>(p);
		if (resa)
			std::cout << "Object type is A" << std::endl;

		B *resb = dynamic_cast<B*>(p);
		if (resb)
			std::cout << "Object type is B" << std::endl;

		C *resc = dynamic_cast<C*>(p);
		if (resc)
			std::cout << "Object type is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &res = dynamic_cast<A&>(p);
		(void) res;
		std::cout << "Object type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &res = dynamic_cast<B&>(p);
		(void) res;
		std::cout << "Object type is B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &res = dynamic_cast<C&>(p);
		(void) res;
		std::cout << "Object type is C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
int main()
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
}