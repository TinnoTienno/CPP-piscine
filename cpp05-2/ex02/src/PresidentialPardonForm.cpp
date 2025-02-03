/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:18:29 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 16:56:58 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("Presidential pardon form", 25, 5),
m_target(target) { }

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExec(executor);
	std::cout << "ATTENTION CITIZENS : " << std::endl;
	std::cout << "After considering every celestial aspects of our mortal lives, the Great and Merciful Lord Beeblebrox has decided to pardon " << m_target << "'s attrocious crimes."<< std::endl;
	std::cout << "Blessed be the Lord and may his light shine upon us." << std::endl;
	
}