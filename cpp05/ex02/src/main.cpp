/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:54:18 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/05 13:04:28 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "TEST" << std::endl;
	try
	{
		Bureaucrat Matthew("Matthew", 145);
		ShrubberyCreationForm tree("tree");
		
		Matthew.signForm(tree);
		Matthew.executeForm(tree);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "TEST" << std::endl;
	try
	{
		Bureaucrat John("John", 35);
		RobotomyRequestForm Matthew("Matthew");
		
		John.signForm(Matthew);
		John.executeForm(Matthew);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "TEST" << std::endl;
	try
	{
		Bureaucrat Russel("Russel", 6);
		PresidentialPardonForm John("John");
		
		Russel.signForm(John);
		Russel.executeForm(John);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
}