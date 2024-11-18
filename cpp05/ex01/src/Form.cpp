/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 14:01:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form() : m_name("Default"), m_isSigned(false), m_gradeToSign(1), m_gradeToExec(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &obj) : m_name(obj.getName()), m_isSigned(false), m_gradeToSign(obj.getGradeToSign()), m_gradeToExec(obj.getGradeToExec()) // sets isSigned to false so not to get false positives
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = obj;
}

Form::Form(const std::string &str, const int &sign, const int &exec) : m_name(str), m_isSigned(false), m_gradeToSign(sign), m_gradeToExec(exec)
{
	if (m_gradeToExec < 1)
		throw (Form::GradeTooHighException(m_gradeToExec));
	else if (m_gradeToSign < 1)
		throw (Form::GradeTooHighException(m_gradeToSign));
	else if (m_gradeToExec > 150)	
		throw (Form::GradeTooLowException(m_gradeToExec));
	else if (m_gradeToSign > 150)	
		throw (Form::GradeTooLowException(m_gradeToSign));
	std::cout << "Form data constructor called" << std::endl;
}

Form& Form::operator=(const Form &obj) // Perfectly useless as it is
{
	std::cout << "Form copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	m_isSigned = obj.getBool();
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


const std::string& Form::getName() const { return m_name; }

const int& 	Form::getGradeToSign() const { return m_gradeToSign; }

const int& 	Form::getGradeToExec() const { return m_gradeToExec; }

const bool& Form::getBool() const		 { return m_isSigned; }


void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw (Form::GradeTooLowException(obj.getGrade(), this->getGradeToSign()));
	else
		m_isSigned = true;
}


Form::GradeTooHighException::GradeTooHighException() : m_grade(0) { }

Form::GradeTooHighException::GradeTooHighException(const int &i) : m_grade(i) { }

const int& Form::GradeTooHighException::getGrade() const { return this->m_grade; }

const char* Form::GradeTooHighException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return "Error:Form::GradeTooHighException";
}

Form::GradeTooLowException::GradeTooLowException() : m_burGrade(150), m_formGrade(0) { }

Form::GradeTooLowException::GradeTooLowException(const int &i) : m_burGrade(150), m_formGrade(i){ }

Form::GradeTooLowException::GradeTooLowException(const int &i1, const int &i2) : m_burGrade(i1), m_formGrade(i2) { }

const int& Form::GradeTooLowException::getBurGrade() const { return m_burGrade; }

const int& Form::GradeTooLowException::getFormGrade() const { return m_formGrade; }

const char* Form::GradeTooLowException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return "Error:Form::GradeTooLowException";
}

std::ostream& operator<<(std::ostream &os, Form const &obj) // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
{
	os << "Form : " << obj.getName() << ",grade to sign : " << obj.getGradeToSign() << ", grade to execute : " << obj.getGradeToExec() << "signed ?";
	if (obj.getBool())
		std::cout << " yes" << std::endl;
	else
		std::cout << " no" << std::endl;
	return os;
}
