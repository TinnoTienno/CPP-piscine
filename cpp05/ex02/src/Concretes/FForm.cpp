/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:27:57 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 16:02:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FForm.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

typeID FForm::getTypeID(const std::string &type)
{
	if (type == "PresidentialPardonForm")
		return PresidentialPardonFormID;
	if (type == "RobotomyRequestForm")
		return RobotomyRequestFormID;
	if (type == "ShrubberyCreationForm")
		return ShrubberyCreationFormID;
	return DefaultID;
}

AForm *FForm::make(const std::string &type, const std::string &target)
{
	switch (getTypeID(type))
	{
		case DefaultID :
			throw std::runtime_error("Form type not found");
		case PresidentialPardonFormID :
			return new PresidentialPardonForm(target);
		case RobotomyRequestFormID :
			return new RobotomyRequestForm(target);
		case ShrubberyCreationFormID :
			return new ShrubberyCreationForm(target);
	}
}
