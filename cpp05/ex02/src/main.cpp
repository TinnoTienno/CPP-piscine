/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:54:18 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 18:26:52 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum FormKind {
	FORM_SHRUBERRY = 0,
	FORM_ROBOTOMY,
	FORM_PRESIDENTIAL
};

typedef AForm (*AbstractFormConstructor)(std::string &);

AForm MakeShruberryForm(const std::string&);

static FormKind form_kind_from_repr(const std::string &repr) {
	if (repr == "Shruberry")
		return (FORM_SHRUBBERY);
	/* ... */
} 

static AbstractFormConstructor consructor_from_kind(FormKind kind) {
	/* let dispatch be array of constructor function pointers */	
	/* return dispatch[kind] (optionally throwing if kind > len(dispatch) */
}

int main()
{
	try
	{
		Bureaucrat Matthew("Matthew", 7);
		ShrubberyCreationForm tree("tree");
		
		Matthew.signForm(tree);
		Matthew.executeForm(tree);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat John("John", 35);
		RobotomyRequestForm Matthew("Matthew");
		
		John.signForm(Matthew);
		John.executeForm(Matthew);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Russel("Russel", 6);
		PresidentialPardonForm John("John");
		
		Russel.signForm(John);
		Russel.executeForm(John);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
}