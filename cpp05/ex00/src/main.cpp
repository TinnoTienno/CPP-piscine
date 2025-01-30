/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 12:42:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	unsigned int t = 0;
	std::cout << "TEST n" << ++t << std::endl;
	Bureaucrat Nikolai("Nikolai", 140);
	std::cout << Nikolai << std::endl;
	try
	{
		std::cout << "TEST n" << ++t << std::endl;
		Bureaucrat Boris("Boris", 155);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "TEST n" << ++t << std::endl;
		Bureaucrat Igor("Igor", 150);
		std::cout << "Igor got demoted" << std::endl;
		Igor--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "TEST n" << ++t << std::endl;
		Bureaucrat Vladimir("Vladimir", 1);
		std::cout << "Vladimir got promoted again, by whom may I ask ?" << std::endl;
		Vladimir++;
		std::cout << "Nevermind" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}