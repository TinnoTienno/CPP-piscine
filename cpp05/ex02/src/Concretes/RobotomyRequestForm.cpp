/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 17:01:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("RobotomyRequestForm", 72, 45), m_target("Nobody") { }

RobotomyRequestForm::RobotomyRequestForm(const std::string &str) : 
	AForm("RobotomyRequestForm", 72, 45), m_target(str) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : 
	AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()), m_target(obj.m_target) { }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm&) { return *this; }

RobotomyRequestForm::~RobotomyRequestForm() { }

const std::string& RobotomyRequestForm::getTarget() const { return m_target; }

void RobotomyRequestForm::execute(Bureaucrat const &obj) const
{
	if (!this->getBool())
		throw(AForm::IsntSignedException(this->getName()));
	if (obj.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException(this->getName(), this->getGradeToExec(), obj.getName(), obj.getGrade()));
	std::cout << "**Drilling noises**" << std::endl;
	srand(time(0));
	static unsigned int nbSuccesses = 0;
	static unsigned int nbTries = 0;
	if (rand() % 2)
		std::cout << "Robotomy on "<< this->getTarget() << " has failed." << std::endl << this->getTarget() << "is now officially retired." << std::endl;
	else
	{
		std::cout << "Contrary to most data predictions, " << this->getTarget() << " has been robotomized successfully" << std::endl;
		nbSuccesses++;
	}
	std::cout << "Successful tries so far : " << nbSuccesses << "/" << ++nbTries << std::endl;
}
