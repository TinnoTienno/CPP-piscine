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

AForm::AForm() : m_name("Default"), m_isSigned(false), m_gradeToSign(1), m_gradeToExec(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &obj) : m_name(obj.getName()), m_isSigned(false), m_gradeToSign(obj.getGradeToSign()), m_gradeToExec(obj.getGradeToExec()) // sets isSigned to false so not to get false positives
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = obj;
}

AForm::AForm(const std::string &str, const int &sign, const int &exec) : m_name(str), m_isSigned(false), m_gradeToSign(sign), m_gradeToExec(exec)
{
	if (m_gradeToExec < 1)
		throw (AForm::GradeTooHighException(m_gradeToExec));
	else if (m_gradeToSign < 1)
		throw (AForm::GradeTooHighException(m_gradeToSign));
	else if (m_gradeToExec > 150)	
		throw (AForm::GradeTooLowException(m_gradeToExec));
	else if (m_gradeToSign > 150)	
		throw (AForm::GradeTooLowException(m_gradeToSign));
	std::cout << "AForm data constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &obj) // Perfectly useless as it is
{
	std::cout << "AForm copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	m_isSigned = obj.getBool();
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}


const std::string& AForm::getName() const { return m_name; }

const int& 	AForm::getGradeToSign() const { return m_gradeToSign; }

const int& 	AForm::getGradeToExec() const { return m_gradeToExec; }

const bool& AForm::getBool() const { return m_isSigned ; }

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException(obj.getGrade(), this->getGradeToSign()));
	else
		m_isSigned = true;
}


AForm::GradeTooHighException::GradeTooHighException() : m_grade(0) { }

AForm::GradeTooHighException::GradeTooHighException(const int &i) : m_grade(i) { }

const int& AForm::GradeTooHighException::getGrade() const { return m_grade; }

const char* AForm::GradeTooHighException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return "Error:AForm::GradeTooHighException";
}

AForm::GradeTooLowException::GradeTooLowException() : m_burGrade(150), m_formGrade(0) { }

AForm::GradeTooLowException::GradeTooLowException(const int &i) : m_burGrade(150), m_formGrade(i){ }

AForm::GradeTooLowException::GradeTooLowException(const int &i1, const int &i2) : m_burGrade(i1), m_formGrade(i2) { }

const int& AForm::GradeTooLowException::getBurGrade() const { return m_burGrade; }

const int& AForm::GradeTooLowException::getFormGrade() const { return m_formGrade; }

const char* AForm::GradeTooLowException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return "Error:AForm::GradeTooLowException";
}

std::ostream& operator<<(std::ostream &os, AForm const &obj) // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
{
	os << "AForm : " << obj.getName() << ",grade to sign : " << obj.getGradeToSign() << ", grade to execute : " << obj.getGradeToExec() << "signed ?";
	if (obj.getBool())
		std::cout << " yes" << std::endl;
	else
		std::cout << " no" << std::endl;
	return os;
}

const char* AForm::IsntSignedException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return "Error:AForm::IsntSignedException";
}