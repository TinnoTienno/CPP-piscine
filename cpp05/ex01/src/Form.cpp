/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:26:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 18:07:18 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Default"), _sign(0), _signingGrade(1), _executingGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}
Form::Form(const Form &obj) : _name(obj.getName()), _signingGrade(obj.getSigning()), _executingGrade(obj.getExec())
{
	*this = obj;
	std::cout << "Form copy constructor called" << std::endl;
}
Form::Form(const std::string &name, const int &signing, const int &executing) : _name(name), _sign(0), _signingGrade(signing), _executingGrade(executing)
{
	if (_signingGrade > 150 || _executingGrade > 150)
		throw(Form::GradeTooLowException);
	else if (_signingGrade < 1 || _executingGrade < 1)
		throw(Form::GradeTooHighException);
	std::cout << "Form data constructor called" << std::endl;
}
Form& Form::operator=(const Form &obj)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->setSign(obj.getBool());
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}
std::string Form::getName() const			{ return (this->_name); }
int			Form::getSigning() const		{ return (this->_signingGrade); }
int			Form::getExec()	const			{ return (this->_executingGrade); }
bool		Form::getBool()	const			{ return (this->_sign); }
void		Form::setSign(const bool &val)	{ this->_sign = val; }

void 		Form::beSigned(const Bureaucrat &bur)
{
	if (this->getSigning() < bur.getGrade())
	{
		_sign = 0;
		throw (Form::GradeTooLowException);
	}
	else
		_sign = 1;
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error : GradeTooLowException\n");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error : GradeTooHighException\n");
}