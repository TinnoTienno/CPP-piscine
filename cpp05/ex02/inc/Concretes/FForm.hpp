/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:26:24 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 15:36:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FFORM_HPP
#define FFORM_HPP
#include "iostream"
#include "string"

typedef enum
{
	DefaultID,
	PresidentialPardonFormID,
	RobotomyRequestFormID,
	ShrubberyCreationFormID
} typeID;

class AForm;
class FForm
{
	private :
		typeID getTypeID(const std::string &type);
	public :
		AForm *make(const std::string &type, const std::string &target);
}	;

#endif