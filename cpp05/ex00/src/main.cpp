/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 13:10:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		Bureaucrat John("John", 175); // Test a grade thats too low at definition
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": value (" << e.getGrade() << ") > 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": value (" << e.getGrade() << ") < 1" << std::endl;
	}
	try
	{
		Bureaucrat	Jim("Jim", 150);
		Jim.decrement();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Test2 : " << std::endl << e.what() << ": value (" << e.getGrade() << ") > 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Test2 : " << std::endl << e.what() << ": value (" << e.getGrade() << ") < 1" << std::endl;
	}
	try
	{
		Bureaucrat	George("George", 1);
		George.increment();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Test3 : " << std::endl << e.what() << ": value (" << e.getGrade() << ") > 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Test3 : " << std::endl << e.what() << ": value (" << e.getGrade() << ") < 1" << std::endl;
	}
}