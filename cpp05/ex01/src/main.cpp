/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 14:47:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		Form workPermit("Permis de travail", 155, 149);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
	}
	try
	{
		Form workPermit("Permis de travail", 1, 0);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
	}
	try
	{
		Form workPermit("Permis de travail", 120, 119);
		Bureaucrat Hugues("Hugues", 124);

		Hugues.signForm(workPermit);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Test1 : " << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
	}
	
}