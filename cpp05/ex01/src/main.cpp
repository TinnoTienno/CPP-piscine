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
	{
		std::cout << "Test 1 Too low" << std::endl;
		try
		{
			Form workPermit("Permis de travail", 150, 155);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 2 Too high" << std::endl;
		try
		{
			Form workPermit("Permis de travail", 0, 148);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 2 Cant sign" << std::endl;
		try
		{
			Form workPermit("Permis de travail", 15, 148);
			Bureaucrat Tom("Tom", 16);

			Tom.signForm(workPermit);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 2 Can sign" << std::endl << std::endl;
		try
		{
			Form workPermit("Permis de travail", 15, 148);
			Bureaucrat Tom("Tom", 10);

			Tom.signForm(workPermit);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
	{
		std::cout << "Test 2 Cant copy" << std::endl << std::endl;
		try
		{
			Form workPermit("Permis de travail", 15, 148);
			Form newDoc;

			newDoc = workPermit;
			Bureaucrat Tom("Tom", 10);

			Tom.signForm(newDoc); // if he cant sign it it means the grade to sign was not copied, which is const
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getFormGrade() << ") > 150" << std::endl;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << std::endl << e.what() << ": Grade(" << e.getGrade() << ") < 1" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") > 150" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << std::endl << e.what() << ": Grade (" << e.getGrade() << ") < 1" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() <<std::endl;
		}	
	}
}