/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 14:48:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm() : 
	m_name("Default"), m_isSigned(false), m_gradeToSign(1), m_gradeToExec(1) { }

AForm::AForm(const AForm &obj) : 
	m_name(obj.getName()), m_isSigned(false), m_gradeToSign(obj.getGradeToSign()), m_gradeToExec(obj.getGradeToExec()) // sets isSigned to false so not to get false positives
		{ checkGrade(); }

AForm::AForm(const std::string &str, const int &sign, const int &exec) : 
	m_name(str), m_isSigned(false), m_gradeToSign(sign), m_gradeToExec(exec)
		{ checkGrade(); }

AForm& AForm::operator=(const AForm &obj) // Perfectly useless as it is
{
	if (this == &obj)
		return *this;
	m_isSigned = obj.getBool();
	return *this;
}

void AForm::checkGrade() const
{
	if (m_gradeToExec < 1)
		throw (AForm::GradeTooHighException(this->getName(), m_gradeToExec));
	else if (m_gradeToSign < 1)
		throw (AForm::GradeTooHighException(this->getName(), m_gradeToSign));
	else if (m_gradeToExec > 150)	
		throw (AForm::GradeTooLowException(this->getName(), m_gradeToExec));
	else if (m_gradeToSign > 150)	
		throw (AForm::GradeTooLowException(this->getName(), m_gradeToSign));
}

AForm::~AForm() { }

const std::string& AForm::getName() const { return m_name; }

const int& 	AForm::getGradeToSign() const { return m_gradeToSign; }

const int& 	AForm::getGradeToExec() const { return m_gradeToExec; }

const bool& AForm::getBool() const { return m_isSigned ; }

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException(this->getName(), this->getGradeToSign(), obj.getName(), obj.getGrade()));
	else
		m_isSigned = true;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &name, const int &grade) : 
	m_message("error: GradeTooHigh: Form " + name + ": " + itoa(grade)) { }

const char* AForm::GradeTooHighException::what() const throw() { return m_message.c_str(); }// Throw meaning it wont throw any exception / to prevent handling more than one exception at a time 

AForm::GradeTooHighException::~GradeTooHighException() throw() { }

AForm::GradeTooLowException::GradeTooLowException(const std::string &name, const int &grade) : 
	m_message("error: GradeTooLow: Form " + name + ": " + itoa(grade)) { }

AForm::GradeTooLowException::GradeTooLowException(const std::string &name, const int &grade, const std::string &bureaucratName, const int &bureaucratGrade) :
	m_message("error: GradeTooLow: Form " + name + ": " + itoa(grade) + ": Bureaucrat " + bureaucratName + ": " + itoa(bureaucratGrade)) { }

const char* AForm::GradeTooLowException::what() const throw() { return m_message.c_str(); } // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time

AForm::GradeTooLowException::~GradeTooLowException() throw() { }

std::ostream& operator<<(std::ostream &os, AForm const &obj) // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
{
	os << "AForm : " << obj.getName() << ",grade to sign : " << obj.getGradeToSign() << ", grade to execute : " << obj.getGradeToExec() << "signed ?";
	if (obj.getBool())
		std::cout << " yes" << std::endl;
	else
		std::cout << " no" << std::endl;
	return os;
}

AForm::IsntSignedException::IsntSignedException(const std::string &name) : 
	m_message("error : IsntSigned: Form: " + name) { }

AForm::IsntSignedException::~IsntSignedException() throw() { }

const char* AForm::IsntSignedException::what() const throw() { return m_message.c_str(); }// Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
	