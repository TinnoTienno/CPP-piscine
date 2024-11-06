/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:42:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 17:50:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Templates.hpp"
#include <string>

int main()
{
	int a = 2;
	int b = 8;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	::swap(a, b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	
	std::cout << "min : " << ::min(a, b) << std::endl;
	std::cout << "max : " << ::max(a, b) << std::endl;

	std::string c = "Chaine1";
	std::string d = "Chaine2";

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "min : " << ::min(c, d) << std::endl;
	std::cout << "max : " << ::max(c, d) << std::endl;

 }