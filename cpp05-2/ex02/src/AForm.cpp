/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:25:47 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 12:49:35 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : m_name("Empty sheet"), m_isSigned(false), m_signingGrade(1), m_execGrade(1) { }
AForm::AForm(const std::string &name) : m_name(name), m_isSigned(false), m_signingGrade(1), m_execGrade(1) { }
AForm::AForm(const std::string &name, const unsigned short &signingGrade, const unsigned short &execGrade) : 
m_name(name), 
m_isSigned(false),
m_signingGrade(signingGrade), 
m_execGrade(execGrade) { checkGrade(); }
AForm::AForm(const AForm &obj) : 
m_name(obj.getName()), 
m_isSigned(obj.getBool()),
m_signingGrade(obj.getSigningGrade()),
m_execGrade(obj.getExecGrade()) { checkGrade(); }
AForm &AForm::operator=(const AForm &) { return *this; }
AForm::~AForm() { }
void AForm::checkGrade()
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

std::string	AForm::getName() const { return this->m_name; }
bool		AForm::getBool() const { return this->m_isSigned; }
short		AForm::getSigningGrade() const { return this->m_signingGrade; }
short		AForm::getExecGrade() const { return this->m_execGrade; }
void		AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSigningGrade() < bureaucrat.getGrade())
		throw GradeTooLowException(bureaucrat.getGrade());
	m_isSigned = true;
}

void		AForm::checkExec(const Bureaucrat &bureaucrat) const
{
	if (!m_isSigned)
		throw std::runtime_error("Form is not signed yet");
	if (m_execGrade < bureaucrat.getGrade())
		throw GradeTooLowException(bureaucrat.getGrade());
}

AForm::GradeTooHighException::GradeTooHighException(const unsigned short &grade) { m_message = (std::string) "error: GradeTooHigh: " + itoa(grade); }
const char* AForm::GradeTooHighException::what() const throw() { return m_message.c_str(); }
AForm::GradeTooHighException::~GradeTooHighException() throw() { }

AForm::GradeTooLowException::GradeTooLowException(const unsigned short &grade) { m_message = (std::string) "error: GradeTooLow: " + itoa(grade); }
const char* AForm::GradeTooLowException::what() const throw() { return m_message.c_str(); }
AForm::GradeTooLowException::~GradeTooLowException() throw() { }

std::ostream& operator<<(std::ostream &out, AForm const& obj)
{
	out << obj.getName() << " AForm signing grade " << obj.getSigningGrade() << ", executing grade " << obj.getExecGrade();
	if (obj.getBool())
		out << ", has been signed." << std::endl;
	else
		out << ", has not been signed." << std::endl;
	return out;
}