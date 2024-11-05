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

RobotomyRequestForm::RobotomyRequestForm(const std::string &str) : AForm("RobotomyRequestForm", 72, 45), _target(str)
{
	std::cout << "RobotomyRequestForm string constructor called" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const { return (_target) ; }

void RobotomyRequestForm::execute(Bureaucrat const &obj) const
{
	if (!this->getBool())
		throw(AForm::IsntSignedException());
	else if (this->getBool() && obj.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException(obj.getGrade(), this->getGradeToExec()));
	else
	{
		std::cout << "**Drilling noises**" << std::endl;
		srand(time(0));
		int rando = rand();
		if (rando % 2)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else 
			std::cout << "Robotomy on "<< this->getTarget() << " has failed." << std::endl << "Poor fellow" << std::endl;
	}

		
}
