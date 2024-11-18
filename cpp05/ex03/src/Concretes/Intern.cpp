/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:13 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 13:13:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern&) // perfectly useless considering there is no attributs to the class
{
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern&) //same here, useless af
{
	std::cout << "Intern copy assignement operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

static int map_val(std::string level)
{
	std::string tab[3] = {"presidential request", "shrubbery request", "robotomy request"};
	int i = 0;

	while (i < 3)
	{
		if (tab[i] == level)
			return (i);
		i++;
	}
	return (-1);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &burName)
{
	int mapVal = map_val(formName);
	switch (mapVal)
	{
		default :
		{
			std::cout << "Intern couldn't create a form : Wrong format" << std::endl;
			throw ()
			return (NULL);
		}
		case (0) :
		{
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(burName));
		}
		case (1) :
		{
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(burName));
		}
		case (2) :
		{
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(burName));
		}
	}
}
