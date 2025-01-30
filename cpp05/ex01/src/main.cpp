/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 14:41:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>
#define TEST_MESS ">> Test N-"

int main()
{
	Bureaucrat Anya("Anya", 145);
	int t = 0;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		Form drivingLicence("Driving Licence", 151, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		Form drivingLicence("Driving Licence", 146, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		Form drivingLicence("Driving Licence", 145, 100);
		std::cout << drivingLicence << std::endl;
		Anya.signForm(drivingLicence);
		std::cout << drivingLicence << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		Form drivingLicence("Driving Licence", 120, 100);
		std::cout << drivingLicence << std::endl;
		Anya.signForm(drivingLicence);
		std::cout << drivingLicence << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}