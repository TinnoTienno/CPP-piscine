/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:31:35 by noda              #+#    #+#             */
/*   Updated: 2025/01/28 18:56:59 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <sstream>

Bureaucrat::Bureaucrat() : m_name("Stranger"), m_grade(150) { }

Bureaucrat::Bureaucrat(const std::string &name) : m_name(name), m_grade(150) { }

Bureaucrat::Bureaucrat(const std::string &name, const short &grade) : m_name(name), m_grade(grade) { checkGrade(); }

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {	*this = obj; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->m_grade = obj.getGrade();
	checkGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() { }

const std::string &Bureaucrat::getName() const { return this->m_name; }

const unsigned short &Bureaucrat::getGrade() const { return this->m_grade; }

Bureaucrat &Bureaucrat::operator++(int)
{
	this->m_grade--;
	checkGrade();
	return *this;
}

Bureaucrat &Bureaucrat::operator--(int)
{
	this->m_grade++;
	checkGrade();
	return *this;
}

void Bureaucrat::checkGrade()
{
	if (this->getGrade() < 1)
		throw GradeTooHighException(this->getGrade());
	else if (this->getGrade() > 150)
		throw GradeTooLowException(this->getGrade());
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because of " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream &out, Bureaucrat const& obj)
{
	out << obj.getName() << " bureaucrat grade " << obj.getGrade() << ".";
	return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const unsigned short &grade) { m_message = (std::string) "error: GradeTooHigh: " + itoa(grade); }

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return m_message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }

Bureaucrat::GradeTooLowException::GradeTooLowException(const unsigned short &grade) { m_message = (std::string) "error: GradeTooLow: " + itoa(grade); }

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return m_message.c_str();
}

std::string itoa(int nb)
{
	std::ostringstream ss;
	
	ss << nb;
	std::string res = (std::string) ss.str();
	return res;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }


