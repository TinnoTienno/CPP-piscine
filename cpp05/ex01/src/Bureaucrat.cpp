/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:37:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 19:00:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include "Form.hpp"

Bureaucrat::Bureaucrat() 
{
	this->setGrade(1);
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &c)
{
	*this = c;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &str) : _name(str)
{
	this->setGrade(1);
	std::cout << "Bureaucrat string constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &str, const int &i) : _name(str)
{
	std::cout << "Bureaucrat data constructor called" << std::endl;
	this->setGrade(1);
	this->setGrade(i);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->setGrade(obj.getGrade());
	return (*this);
}

void Bureaucrat::increment()			{ this->setGrade(this->getGrade() - 1); }
void Bureaucrat::decrement()			{ this->setGrade(this->getGrade() + 1); }
const std::string&	Bureaucrat::getName() const	{ return (_name); }
int	Bureaucrat::getGrade()	const		{ return (_grade); }

void	Bureaucrat::setGrade(const int &i)	
{
	if (i > 150)
		throw(Bureaucrat::GradeTooLowException);
	if (i < 1)
		throw(Bureaucrat::GradeTooHighException);
	else
		_grade = i;
}

std::ostream& Bureaucrat::operator<<(std::ostream& os)
{
	os << _name << ", bureaucrat grade " << _grade << ".";
	return os;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	_grade = 0;
#ifdef DEBUG_MODE
	std::cout << "GradeTooLowException default constructor" << std::endl;
#endif
}
std::ostream& Bureaucrat::GradeTooLowException::operator<<(std::ostream& os)
{
	os << "Bureaucrat::setGrade: Grade (which is " << _grade << ") > 150 : Grade Too Low." << std::endl;
	return (os);
}

std::ostream& Bureaucrat::GradeTooHighException::operator<<(std::ostream& os)
{
	os << "Bureaucrat::setGrade: Grade (which is " << _grade << ") < 1 : Grade Too High." << std::endl;
	return (os);
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		if (form.getBool())
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
}