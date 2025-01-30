/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 15:24:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), m_target("Nowhere") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &str) : 
	AForm("ShrubberyCreationForm", 145, 137), m_target(str) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : 
	AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()) { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &) { return *this; }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

const std::string& ShrubberyCreationForm::getTarget() const { return m_target; }

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!this->getBool())
		throw(AForm::IsntSignedException(this->getName()));
	else if (bureaucrat.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException(this->getName(), this->getGradeToExec(), bureaucrat.getName(), bureaucrat.getGrade()));
	else
	{
		std::ofstream of((this->getTarget() + "_shrubbery").c_str());
		of.exceptions (std::ofstream::badbit);
		if (!of.is_open())
			throw(std::runtime_error("error: runtime_error: ShrubberyCreationForm: Couldn't open the file"));
		of << ASCII_TREE;
	}
}
