/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:05:41 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 15:47:29 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "string"

class RobotomyRequestForm : public AForm
{
	private :
		const std::string	m_target;
	public :
		RobotomyRequestForm(const std::string &target);
		void		execute(Bureaucrat const &executor) const;
}	;
#endif