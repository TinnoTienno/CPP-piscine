/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:09:10 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 16:59:36 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "FForm.hpp"

int main()
{
	FForm Factory;
	AForm *Treeplanting;
	AForm *Pardon;
	AForm *Robotomy;
	int t = 1;
	Bureaucrat Boris("Boris", 140);
	Bureaucrat Vladimir("Vladimir", 62);
	Bureaucrat Vasili("Vasili", 5);
	
	try
	{
		std::cout << "TEST " << t++ << std::endl;
		Treeplanting = Factory.make("ShrubberyCreationForm", "Dijon");
		Boris.signForm(*Treeplanting);
		Boris.executeForm(*Treeplanting);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Treeplanting;
	try
	{
		std::cout << "TEST " << t++ << std::endl;
		Treeplanting = Factory.make("ShrubberyCreationForm", "Chenove");
		Vladimir.signForm(*Treeplanting);
		Vladimir.executeForm(*Treeplanting);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Treeplanting;
	try
	{
		std::cout << "TEST " << t++ << std::endl;
		Pardon = Factory.make("PresidentialPardonForm", "Freddie the misfit");
		Boris.signForm(*Pardon);
		Boris.executeForm(*Pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Pardon;
	try
	{
		std::cout << "TEST " << t++ << std::endl;
		Pardon = Factory.make("PresidentialPardonForm", "Freddie the misfit");
		Vasili.signForm(*Pardon);
		Vasili.executeForm(*Pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Pardon;
	try
	{
		std::cout << "TEST " << t++ << std::endl;
		Robotomy = Factory.make("RobotomyRequestForm", "Freddie the misfit");
		Vladimir.signForm(*Robotomy);
		Vladimir.executeForm(*Robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Robotomy;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << "TEST " << t++ << std::endl;
			Robotomy = Factory.make("RobotomyRequestForm", "Freddie the misfit");
			Vasili.signForm(*Robotomy);
			Vasili.executeForm(*Robotomy);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete Robotomy;
	}
}