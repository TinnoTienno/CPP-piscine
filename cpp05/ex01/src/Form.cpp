/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 14:48:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &obj) : _name(obj.getName()), _isSigned(false), _gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec()) // sets isSigned to false so not to get false positives
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = obj;
}

Form::Form(const std::string &str, const int &sign, const int &exec) : _name(str), _isSigned(false), _gradeToSign(sign), _gradeToExec(exec)
{
	if (_gradeToExec < 1)
		throw (Form::GradeTooHighException(_gradeToExec));
	else if (_gradeToSign < 1)
		throw (Form::GradeTooHighException(_gradeToSign));
	else if (_gradeToExec > 150)	
		throw (Form::GradeTooLowException(_gradeToExec));
	else if (_gradeToSign > 150)	
		throw (Form::GradeTooLowException(_gradeToSign));
	std::cout << "Form data constructor called" << std::endl;
}

Form& Form::operator=(const Form &obj) // Perfectly useless as it is
{
	std::cout << "Form copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	_isSigned = obj.getBool();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


const std::string& Form::getName() const { return (_name); }

const int& 	Form::getGradeToSign() const { return (_gradeToSign); }

const int& 	Form::getGradeToExec() const { return (_gradeToExec); }

const bool& Form::getBool() const		 { return (_isSigned) ; }


void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getGradeToSign())
		throw (Form::GradeTooLowException(obj.getGrade(), this->getGradeToSign()));
	else
		_isSigned = true;
}


Form::GradeTooHighException::GradeTooHighException() : _grade(0) { }

Form::GradeTooHighException::GradeTooHighException(const int &i) : _grade(i) { }

const int& Form::GradeTooHighException::getGrade() const 	{ return (_grade); }

const char* Form::GradeTooHighException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return ("Error:Form::GradeTooHighException");
}

Form::GradeTooLowException::GradeTooLowException() : _burGrade(150), _formGrade(0) { }

Form::GradeTooLowException::GradeTooLowException(const int &i) : _burGrade(150), _formGrade(i){ }

Form::GradeTooLowException::GradeTooLowException(const int &i1, const int &i2) : _burGrade(i1), _formGrade(i2) { }

const int& Form::GradeTooLowException::getBurGrade() const { return(_burGrade); }

const int& Form::GradeTooLowException::getFormGrade() const { return(_formGrade); }

const char* Form::GradeTooLowException::what() const throw() // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
{
	return ("Error:Form::GradeTooLowException");
}

std::ostream& operator<<(std::ostream &os, Form const &obj) // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
{
	os << "Form : " << obj.getName() << ",grade to sign : " << obj.getGradeToSign() << ", grade to execute : " << obj.getGradeToExec() << "signed ?";
	if (obj.getBool())
		std::cout << " yes" << std::endl;
	else
		std::cout << " no" << std::endl;
	return (os);
}
