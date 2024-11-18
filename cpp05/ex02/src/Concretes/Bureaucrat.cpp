/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:54:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 14:15:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150) // Set default value at the bottom
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &str, const int &i) : m_name(str) // was not clearly asked for in the subject but then again -> "Any attempt to instantiate a Bureaucrat using an invalid grade..."
{
	this->setGrade(i);
	std::cout << "Bureaucrat data constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : m_name(obj.getName()) //m_name being a const needs to be set before construction
{
	*this = obj;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) // operator= is rendered useless here considering the const variable (cant redefine a m_name)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	this->setGrade(obj.getGrade());
	return *this;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj) // done as asked in the subject
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (os);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


const std::string& Bureaucrat::getName()const 
{
	return (m_name);
}

const int& Bureaucrat::getGrade()const 
{
	return (m_grade);
}

void	Bureaucrat::setGrade(const int &i) // exception are thrown for main to catch
{
	if (i < 1)
	{
		throw(Bureaucrat::GradeTooHighException(i));
	}
	else if (i > 150)
	{
		throw(Bureaucrat::GradeTooLowException(i));
	}
	else
		m_grade = i;
}

Bureaucrat&	Bureaucrat::operator++() // setGrade is called to make code somewhat more dynamic
{
	this->setGrade(this->getGrade() - 1);
	return *this;
}

Bureaucrat&	Bureaucrat::operator--()
{
	this->setGrade(this->getGrade() + 1);
	return *this;
}
void	Bureaucrat::signForm(AForm &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << obj.getName() << " because " << e.what() << ": Bureaucrat grade(" << e.getBurGrade() << ") > AForm signing grade(" << e.getFormGrade() << ")." << std::endl; 
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}
}

void	Bureaucrat::executeForm(AForm const &obj)
{
	try
	{
		obj.execute(*this);
		std::cout << this->getName() << " executed " << obj.getName() << "." << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't execute " << obj.getName() << " because " << e.what() << ": Bureaucrat grade(" << e.getBurGrade() << ") > AForm executing grade(" << e.getFormGrade() << ")." << std::endl; 
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}
	
}


Bureaucrat::GradeTooHighException::GradeTooHighException() : m_grade(0) { }
Bureaucrat::GradeTooHighException::GradeTooHighException(const int &i) : m_grade(i) { }

const int& Bureaucrat::GradeTooHighException::getGrade() const
{
	return (m_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() // Cant display the grade because of many reasons - main reason being the function returning a char* instead of a string
{
	return ("Bureaucrat::setGrade: Grade too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : m_grade(0) { }
Bureaucrat::GradeTooLowException::GradeTooLowException(const int &i) : m_grade(i) { }

const int& Bureaucrat::GradeTooLowException::getGrade() const
{
	return (m_grade);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Bureaucrat::setGrade: Grade too low");
}
