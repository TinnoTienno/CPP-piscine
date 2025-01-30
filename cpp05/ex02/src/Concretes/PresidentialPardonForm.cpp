/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 17:01:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), m_target("Nobody") { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : 
	AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()), m_target(obj.m_target) { }

PresidentialPardonForm::PresidentialPardonForm(const std::string &str) : 
	AForm("PresidentialPardonForm", 25, 5), m_target(str) { }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &)
	{ return *this; }

PresidentialPardonForm::~PresidentialPardonForm() { }

const std::string& PresidentialPardonForm::getTarget() const { return m_target; }

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!this->getBool())
		throw (AForm::IsntSignedException(this->getName()));
	else if (this->getBool() && bureaucrat.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException(this->getName(), this->getGradeToExec(), bureaucrat.getName(), bureaucrat.getGrade()));
	else
	{
		std::cout << "**Attention citizens !**" << std::endl;
		std::cout << this->getTarget() << " has been pardoned by the great Zaphod Beeblebrox. May his holy light shine upon the rightful." << std::endl;
	}	
}
