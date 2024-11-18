/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/05 12:49:58 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	{
		std::cout << "Test 1 too high grade" << std::endl;
		try
		{
			Bureaucrat John("John", -1); 
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") > 150" << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}
	}
	{
		std::cout << "Test 2 too low grade" << std::endl;
		try
		{
			Bureaucrat John("John", 152);
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") > 150" << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 3 good grade" << std::endl;
		try
		{
			Bureaucrat John("John", 150);
			std::cout << John.getGrade() << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") > 150" << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 4 good grade plus decrement" << std::endl;
		try
		{
			Bureaucrat John("John", 150);
			--John;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") > 150" << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 5 cannonical tests" << std::endl;
		try
		{
			Bureaucrat John("John", 150);
			std::cout << "John getgrade : " << John.getGrade() << std::endl;
			Bureaucrat Matthew("Matthew", 10);
			std::cout << "Matthew getgrade : " << Matthew.getGrade() << std::endl;
			Matthew = John;
			std::cout << "Matthew getgrade : " << Matthew.getGrade() << std::endl;
			Bureaucrat Tim(John);
			std::cout << "Tim getgrade : " << Tim.getGrade() << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") > 150" << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
}