/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:54:18 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 16:03:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "FForm.hpp"
#define TEST_MESS ">> Test N-"

int main()
{
	FForm factory;
	Bureaucrat Boris("Boris", 147);
	Bureaucrat Anastasia("Anastasia", 70);
	Bureaucrat Vladimir("Vladimir", 3);
	AForm *form;
	unsigned int t = 0;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("PresidentialPardonForm", "John the brute");
		Boris.signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("ERROR", "John the brute");
		Boris.signForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("RobotomyRequestForm", "John the brute");
		Boris.signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("ShrubberyCreationForm", "Moscou");
		Boris.signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("ShrubberyCreationForm", "Moscou");
		Anastasia.signForm(*form);
		Vladimir.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("RobotomyRequestForm", "Moscou");
		Vladimir.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("RobotomyRequestForm", "Moscou");
		Vladimir.signForm(*form);
		Vladimir.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	try
	{
		std::cout << TEST_MESS << ++t << std::endl;
		form = factory.make("PresidentialPardonForm", "Moscou");
		Vladimir.signForm(*form);
		Vladimir.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
}