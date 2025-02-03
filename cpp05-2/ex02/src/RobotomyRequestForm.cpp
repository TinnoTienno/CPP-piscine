/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SRobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:44:54 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 15:04:02 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : 
AForm("Robotomy request form", 72, 45),
m_target(target) { }

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExec(executor);
	std::cout << "Bzzzzzzzz" << std::endl;
	static unsigned int nbOfSuccesses = 0;
	switch (rand() % 2)
	{
		case 0 :
		{
			std::cout << "Robotomy failed, " << m_target << " is offically retired." << std::endl;
			break;
		}
		case 1 :
		{
			std::cout << "Contrary to everyone's expectation, the robotomy procedure is a success, " << m_target << " is now offically a robot." << std::endl;
			nbOfSuccesses++;
			break ;
		}
	}
	static unsigned int nbOfTries = 0;
	std::cout << "Successful attempts so far : " << nbOfSuccesses << "/" << ++nbOfTries << std::endl;
}