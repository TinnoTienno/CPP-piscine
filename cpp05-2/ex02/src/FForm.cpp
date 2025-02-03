/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:03:34 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 15:42:04 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FForm.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm *FForm::make(const std::string &type, const std::string &target)
{
	switch (getEnum(type))
	{
		case shrubberyCreationForm:
			return new ShrubberyCreationForm(target);
		case robotomyRequestForm :
			return new RobotomyRequestForm(target);
		case presidentialPardonForm:
			return new PresidentialPardonForm(target);\
		default :
		return NULL;
	}
}

e_type FForm::getEnum(const std::string &type)
{
	if (type == "ShrubberyCreationForm")
		return shrubberyCreationForm;
	else if (type == "RobotomyRequestForm")
		return robotomyRequestForm;
	else if (type == "PresidentialPardonForm")
		return presidentialPardonForm;
	return defaultType;
}
