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

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _isSigned(false), _gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec()) // sets isSigned to false so not to get false positives
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = obj;
}

AForm::AForm(const std::string &str, const int &sign, const int &exec) : _name(str), _isSigned(false), _gradeToSign(sign), _gradeToExec(exec)
{
	if (_gradeToExec < 1)
		throw (AForm::GradeTooHighException(_gradeToExec));
	else if (_gradeToSign < 1)
		throw (AForm::GradeTooHighException(_gradeToSign));
	else if (_gradeToExec > 150)	
		throw (AForm::GradeTooLowException(_gradeToExec));
	else if (_gradeToSign > 150)	
		throw (AForm::GradeTooLowException(_gradeToSign));
	std::cout << "AForm data constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &obj) // Perfectly useless as it is
{
	std::cout << "AForm copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	_isSigned = obj.getBool();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}


const std::string& AForm::getName() const { return (_name); }

const int& 	AForm::getGradeToSign() const { return (_gradeToSign); }

const int& 	AForm::getGradeToExec() const { return (_gradeToExec); }

const bool& AForm::getBool() const		 { return (_isSigned) ; }

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException(obj.getGrade(), this->getGradeToSign()));
	else
		_isSigned = true;
}


AForm::GradeTooHighException::GradeTooHighException() : _grade(0) { }

AForm::GradeTooHighException::GradeTooHighException(const int &i) : _grade(i) { }

const int& AForm::GradeTooHighException::getGrade() const 	{ return (_grade); }

const char* AForm::GradeTooHighException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return ("Error:AForm::GradeTooHighException");
}

AForm::GradeTooLowException::GradeTooLowException() : _burGrade(150), _formGrade(0) { }

AForm::GradeTooLowException::GradeTooLowException(const int &i) : _burGrade(150), _formGrade(i){ }

AForm::GradeTooLowException::GradeTooLowException(const int &i1, const int &i2) : _burGrade(i1), _formGrade(i2) { }

const int& AForm::GradeTooLowException::getBurGrade() const { return(_burGrade); }

const int& AForm::GradeTooLowException::getFormGrade() const { return(_formGrade); }

const char* AForm::GradeTooLowException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return ("Error:AForm::GradeTooLowException");
}

std::ostream& operator<<(std::ostream &os, AForm const &obj) // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
{
	os << "AForm : " << obj.getName() << ",grade to sign : " << obj.getGradeToSign() << ", grade to execute : " << obj.getGradeToExec() << "signed ?";
	if (obj.getBool())
		std::cout << " yes" << std::endl;
	else
		std::cout << " no" << std::endl;
	return (os);
}

const char* AForm::IsntSignedException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return ("Error:AForm::IsntSignedException");
}