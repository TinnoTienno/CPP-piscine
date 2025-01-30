/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:43 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 14:50:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form() : 
	m_name("Default"), m_isSigned(false), m_gradeToSign(1), m_gradeToExec(1) 
		{ checkGrade(); }

Form::Form(const Form &obj) : 
	m_name(obj.getName()), m_isSigned(false), m_gradeToSign(obj.getGradeToSign()), m_gradeToExec(obj.getGradeToExec()) // sets isSigned to false so not to get false positives
		{ checkGrade(); }

Form::Form(const std::string &str, const int &sign, const int &exec) : 
	m_name(str), m_isSigned(false), m_gradeToSign(sign), m_gradeToExec(exec)
		{ checkGrade(); }

void Form::checkGrade() const
{
	if (m_gradeToExec < 1)
		throw (Form::GradeTooHighException(this->getName(), m_gradeToExec));
	else if (m_gradeToSign < 1)
		throw (Form::GradeTooHighException(this->getName(), m_gradeToSign));
	else if (m_gradeToExec > 150)	
		throw (Form::GradeTooLowException(this->getName(), m_gradeToExec));
	else if (m_gradeToSign > 150)	
		throw (Form::GradeTooLowException(this->getName(), m_gradeToSign));
}

Form& Form::operator=(const Form &obj) // Perfectly useless as it is
{
	if (this == &obj)
		return *this;
	m_isSigned = obj.getBool();
	return *this;
}

Form::~Form() { }

const std::string& Form::getName() const { return m_name; }

const int& 	Form::getGradeToSign() const { return m_gradeToSign; }

const int& 	Form::getGradeToExec() const { return m_gradeToExec; }

const bool& Form::getBool() const		 { return m_isSigned; }

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw (Form::GradeTooLowException(this->getName(), this->getGradeToSign(), obj.getName(), obj.getGrade()));
	else
		m_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &name, const int &grade) : 
	m_message("error: GradeTooHigh: Form " + name + ": " + itoa(grade)) { }

const char* Form::GradeTooHighException::what() const throw() { return m_message.c_str(); }// Throw meaning it wont throw any exception / to prevent handling more than one exception at a time 

Form::GradeTooHighException::~GradeTooHighException() throw() { }

Form::GradeTooLowException::GradeTooLowException(const std::string &name, const int &grade) : 
	m_message("error: GradeTooLow: Form " + name + ": " + itoa(grade)) { }

Form::GradeTooLowException::GradeTooLowException(const std::string &name, const int &grade, const std::string &bureaucratName, const int &bureaucratGrade) :
	m_message("error: GradeTooLow: Form " + name + ": " + itoa(grade) + ": Bureaucrat " + bureaucratName + ": " + itoa(bureaucratGrade)) { }

const char* Form::GradeTooLowException::what() const throw() { return m_message.c_str(); } // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time

Form::GradeTooLowException::~GradeTooLowException() throw() { }

std::ostream& operator<<(std::ostream &os, Form const &obj) // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
{
	os << "Form : " << obj.getName() << ", grade to sign : " << obj.getGradeToSign() << ", grade to execute : " << obj.getGradeToExec() << ", signed ? ";
	if (obj.getBool())
		std::cout << "yes";
	else
		std::cout << "no";
	return os;
}
