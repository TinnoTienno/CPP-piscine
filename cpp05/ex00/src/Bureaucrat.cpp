/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:37:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 16:55:54 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>
#include <cstring>


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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &d)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	if (this == &d)
		return (*this);
	return (*this);
}

void Bureaucrat::increment()			{ this->setGrade(this->getGrade() - 1); }
void Bureaucrat::decrement()			{ this->setGrade(this->getGrade() + 1); }
std::string	Bureaucrat::getName() const	{ return (_name); }
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::setGrade: Grade < 1 : Grade Too High.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::setGrade: Grade > 150 : Grade Too Low.\n");
}