/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:25:47 by noda              #+#    #+#             */
/*   Updated: 2025/01/28 18:56:09 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : m_name("Empty sheet"), m_isSigned(false), m_signingGrade(1), m_execGrade(1) { }
Form::Form(const std::string &name) : m_name(name), m_isSigned(false), m_signingGrade(1), m_execGrade(1) { }
Form::Form(const std::string &name, const unsigned short &signingGrade, const unsigned short &execGrade) : 
m_name(name), 
m_isSigned(false), 
m_signingGrade(signingGrade), 
m_execGrade(execGrade) { checkGrade(); }
Form::Form(const Form &obj) : 
m_name(obj.getName()), 
m_isSigned(obj.getBool()),
m_signingGrade(obj.getSigningGrade()),
m_execGrade(obj.getExecGrade()) { checkGrade(); }
Form &Form::operator=(const Form &) { return *this; }
Form::~Form() { }
void Form::checkGrade()
{
	if (m_execGrade < 1)
		throw (GradeTooHighException(m_execGrade));
	else if (m_signingGrade < 1)
		throw (GradeTooHighException(m_signingGrade));
	else if (m_execGrade > 150)
		throw (GradeTooLowException(m_execGrade));
	else if (m_signingGrade > 150)
		throw (GradeTooLowException(m_signingGrade));
}

std::string	Form::getName() const { return this->m_name; }
bool		Form::getBool() const { return this->m_isSigned; }
short		Form::getSigningGrade() const { return this->m_signingGrade; }
short		Form::getExecGrade() const { return this->m_execGrade; }
void		Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSigningGrade() < bureaucrat.getGrade())
		throw GradeTooLowException(bureaucrat.getGrade());
	m_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const unsigned short &grade) { m_message = (std::string) "error: GradeTooHigh: " + itoa(grade); }
const char* Form::GradeTooHighException::what() const throw() { return m_message.c_str(); }
Form::GradeTooHighException::~GradeTooHighException() throw() { }

Form::GradeTooLowException::GradeTooLowException(const unsigned short &grade) { m_message = (std::string) "error: GradeTooLow: " + itoa(grade); }
const char* Form::GradeTooLowException::what() const throw() { return m_message.c_str(); }
Form::GradeTooLowException::~GradeTooLowException() throw() { }

std::ostream& operator<<(std::ostream &out, Form const& obj)
{
	out << obj.getName() << " Form signing grade " << obj.getSigningGrade() << ", executing grade " << obj.getExecGrade();
	if (obj.getBool())
		out << ", has been signed." << std::endl;
	else
		out << ", has not been signed." << std::endl;
	return out;
}