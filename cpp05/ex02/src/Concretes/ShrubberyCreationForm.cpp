/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 14:17:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &str) : AForm("ShrubberyCreationForm", 145, 137), m_target(str)
{
	std::cout << "ShrubberyCreationForm string constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec())
{
	*this = obj;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &)
{
	std::cout << "ShrubberyCreationForm copy assignement operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const { return m_target; }

void ShrubberyCreationForm::execute(Bureaucrat const &obj) const
{
	if (!this->getBool())
		throw(AForm::IsntSignedException());
	else if (this->getBool() && obj.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException(obj.getGrade(), this->getGradeToExec()));
	else
	{
		std::ofstream NewFile;
		NewFile.open((this->getTarget() + "_shrubbery").c_str(), std::fstream::out);
		NewFile.exceptions (std::ofstream::badbit);
		NewFile << ASCII_TREE;
		if (NewFile.fail())
			throw(std::ios_base::failure("ShrubberyCreationForm::execute"));
	}
}
