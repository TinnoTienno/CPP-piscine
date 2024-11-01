/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:24:56 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/01 14:24:01 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
		
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) // By default, sets the form to the highest grade
{
	std::cout << "Form default constructor called" << std::endl;
}
Form::Form(const std::string &str, const int &i1, const int &i2) : _name(str), _isSigned(false), _gradeToSign(i1), _gradeToExec(i2)
{
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw(Form::GradeTooLowException);
	else if (_gradeToExec < 1 || _gradeToSign < 1)
		throw(Form::GradeTooHighException);
	std::cout << "Form data constructor called" << std::endl;
}
Form::Form(const Form &obj) :
			_name(obj.getName())
			, _isSigned(false)
			, _gradeToSign(obj.getGradeToSign())
			, _gradeToExec(obj.getGradeToExec())
{
	if (_gradeToExec > 150 || _gradeToSign > 150)
	{
		throw(Form::GradeTooLowException);
	}
	else if (_gradeToExec < 1 || _gradeToSign < 1)
		throw(Form::GradeTooHighException);
	*this = obj;
	std::cout << "Form copy constructor called" << std::endl;
}
Form& Form::operator=(const Form &) // Useless AF
{
	if (this == &obj)
		return (*this);
	return (*this);
	std::cout << "Form copy assignement operator called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string Form::getName() const
{
	return (_name);
}

int 			Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int 			Form::getGradeToExec() const
{
	return (_gradeToExec);
}

bool			Form::getBool() const
{
	return (_isSigned);
}
	
void	Form::beSigned(const Bureaucrat &obj)
{
	if (this->getGradeToSign() < obj.getGrade())
		throw(Form::GradeTooLowException); // Not really satisfying considering its double use
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade too high: < 1");
} 
		
const char* Form::GradeTooLowException::what() const throw() // Problem from the subject : This exception is supposed to manage 2 different contexts.
{
	return ("GradeTooHighException: Grade too Low");
} 