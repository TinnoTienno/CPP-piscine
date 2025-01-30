/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:54:14 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 13:36:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150) { } // Set default value at the bottom

Bureaucrat::Bureaucrat(const std::string &str, const int &grade) : m_name(str), m_grade(grade)// was not clearly asked for in the subject but then again -> "Any attempt to instantiate a Bureaucrat using an invalid grade..."
{
	this->checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : m_name(obj.getName()), m_grade(obj.getGrade()) //m_name being a const needs to be set before construction
{
	this->checkGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) // operator= is rendered useless here considering the const variable (cant redefine a m_name)
{
	if (this == &obj)
		return *this;
	this->setGrade(obj.getGrade());
	return *this;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj) // done as asked in the subject
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat() { } //defined but not too much

const std::string& Bureaucrat::getName()const { return this->m_name; }

const int& Bureaucrat::getGrade()const { return this->m_grade; }

void	Bureaucrat::setGrade(const int &i) // exception are thrown for main to catch
{
	this->m_grade = i;
	this->checkGrade();
}

void	Bureaucrat::checkGrade() const
{
	if (this->m_grade < 1)
		throw(Bureaucrat::GradeTooHighException(this->getName(), this->m_grade));
	else if (this->m_grade  > 150)
		throw(Bureaucrat::GradeTooLowException(this->getName(), this->m_grade));
}

Bureaucrat&	Bureaucrat::operator++(int) // setGrade is called to make code somewhat more dynamic
{
	this->setGrade(this->getGrade() - 1);
	return *this;
}

Bureaucrat&	Bureaucrat::operator--(int)
{
	this->setGrade(this->getGrade() + 1);
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name, const int &grade) : m_message("error: GradeTooHigh: " + (std::string) " Bureaucrat " + name + ": " + itoa(grade)) { }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return m_message.c_str(); }// Cant display the grade because of many reasons - main reason being the function returning a char* instead of a string

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name, const int &grade) : m_message("error: GradeTooLow: " + (std::string) " Bureaucrat " + name + ": " + itoa(grade)) { }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return m_message.c_str(); }

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }

std::string itoa(int nb)
{
	std::stringstream ss;
	ss << nb;
	return ss.str();
}