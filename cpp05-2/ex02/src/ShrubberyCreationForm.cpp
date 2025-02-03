/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:44:54 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 16:58:56 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
AForm("Shrubbery creation form", 145, 137),
m_target(target) { }

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExec(executor);
	srand(time(NULL));
	std::ofstream os((m_target + "_shrubbery").c_str(), std::ios_base::app);
	if (!os.is_open())
		throw std::runtime_error("Couldn't open file");
	std::ifstream *tree;
	std::string line;
	switch ((rand()) % 3)
	{
		case 0 :
			tree = new std::ifstream(FIRST_TREE);
			break ;
		case 1 :
			tree = new std::ifstream(SECOND_TREE);
			break ;
		case 2 :
			tree = new std::ifstream(THIRD_TREE);
			break ;
	}
	if (!(*tree).is_open())
		throw std::runtime_error("Couldn't open file");
	while (getline(*tree, line)) 
    	os << line << std::endl;
	delete (tree);
}