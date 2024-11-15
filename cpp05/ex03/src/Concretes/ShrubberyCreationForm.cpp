/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 17:37:50 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &str) : AForm("ShrubberyCreationForm", 145, 137), _target(str)
{
	std::cout << "ShrubberyCreationForm string constructor called" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const { return (_target) ; }

void ShrubberyCreationForm::execute(Bureaucrat const &obj) const
{
	if (!this->getBool())
		throw(AForm::IsntSignedException());
	else if (this->getBool() && obj.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException(obj.getGrade(), this->getGradeToExec()));
	else
	{
		try
		{
			std::ofstream NewFile((this->getTarget() + "_shrubbery").c_str());
			NewFile << ASCII_TREE;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
